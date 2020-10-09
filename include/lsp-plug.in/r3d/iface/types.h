/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-iface
 * Created on: 18 апр. 2019 г.
 *
 * lsp-r3d-iface is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-r3d-iface is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-r3d-iface. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LSP_PLUG_IN_R3D_IFACE_TYPES_H_
#define LSP_PLUG_IN_R3D_IFACE_TYPES_H_

#include <lsp-plug.in/r3d/iface/version.h>
#include <lsp-plug.in/common/types.h>

namespace lsp
{
    namespace r3d
    {
        /**
         * The type of the actual window handle that backend operates on
         */
        enum window_handle_t
        {
            WND_HANDLE_NONE,    //!< WND_HANDLE_NONE        Backend works in offscreen mode only (without any window subsystem in background) and does not provide init_window
            WND_HANDLE_X11,     //!< WND_HANDLE_X11         X11 window subsystem
            WND_HANDLE_WAYLAND, //!< WND_HANDLE_WAYLAND     Wayland window subsystem
            WND_HANDLE_WINDOWS, //!< WND_HANDLE_WINDOWS     Windows subsystem
        };

        enum pixel_format_t
        {
            PIXEL_RGBA,
            PIXEL_BGRA,
            PIXEL_RGB,
            PIXEL_BGR
        };

        enum matrix_type_t
        {
            MATRIX_PROJECTION,  /* Projection matrix */
            MATRIX_VIEW,        /* View matrix */
            MATRIX_WORLD        /* World matrix for additional transformations if view matrix is not enough */
        };

        enum light_type_t
        {
            LIGHT_NONE,
            LIGHT_POINT,
            LIGHT_DIRECTIONAL,
            LIGHT_SPOT
        };

        enum primitive_type_t
        {
            PRIMITIVE_TRIANGLES,
            PRIMITIVE_WIREFRAME_TRIANGLES,
            PRIMITIVE_LINES,
            PRIMITIVE_POINTS,
        };

        enum buffer_flags_t
        {
            BUFFER_BLENDING     = 1 << 0,
            BUFFER_LIGHTING     = 1 << 1,
            BUFFER_NO_CULLING   = 1 << 2
        };

        #pragma pack(push, 1)
        /**
         * The point in the space
         */
        typedef struct dot4_t
        {
            float       x, y, z, w;
        } dot4_t;

        /**
         * The vector
         */
        typedef struct vec4_t
        {
            float       dx, dy, dz, dw;
        } vec4_t;

        /**
         * The color
         */
        typedef struct color_t
        {
            float       r, g, b, a;
        } color_t;

        typedef struct mat4_t
        {
            float       m[16];
        } mat4_t;
        #pragma pack(pop)

        // Basic type: backend
        struct backend_t;

        // Light parameters
        typedef struct light_t
        {
            light_type_t        type;           /* Light type */
            dot4_t              position;       /* Light position */
            vec4_t              direction;      /* Light direction */
            color_t             ambient;        /* Ambient color */
            color_t             diffuse;        /* Diffuse color */
            color_t             specular;       /* Specular color */
            float               constant;       /* Constant attenuation parameter */
            float               linear;         /* Linear attenuation parameter */
            float               quadratic;      /* Quadratic attenuation parameter */
            float               cutoff;         /* Spot cutoff angle */
        } light_t;

        typedef struct buffer_t
        {
            /* Properties */
            primitive_type_t        type;       // Type of primitive
            size_t                  flags;      // Additional flags, see r3d_buffer_flags_t
            float                   width;      // Point size or line width
            size_t                  count;      // Number of elements in buffer

            /* Vertices */
            struct {
                const dot4_t       *data;       // Vertex data
                size_t              stride;     // Stride between two vertices
                const uint32_t     *indices;    // Vertex indices to use for drawing instead of plain vertex data
            } vertex;

            /* Normals  */
            struct {
                const vec4_t       *data;       // Normal data
                size_t              stride;     // Stride between two normals
                const uint32_t     *indices;    // Vertex indices to use for drawing instead of plain vertex data
            } normal;

            /* Colors */
            struct {
                const color_t      *data;       // Color data
                size_t              stride;     // Stride between two colors
                const uint32_t     *indices;    // Color indices to use for drawing
                color_t             dfl;        // Default color used if color array is not specified
            } color;

            /* Element indices */
            struct {
                const uint32_t     *indices;    // Element indices to use for drawing instead of plain vertex data
            } element;
        } buffer_t;

        /**
         * Export function definition
         * @param dst destination type
         * @param src source type
         */
        template <typename D, typename S>
            inline void export_func(D &dst, const S &src)
            {
                union { D xdst; S xsrc; } uni;
                uni.xsrc    = src;
                dst         = uni.xdst;
            }

        /**
         * Init buffer with default values
         * @param buf buffer to init
         */
        void    init_buffer(buffer_t *buf);
    }
}

#endif /* LSP_PLUG_IN_R3D_IFACE_TYPES_H_ */
