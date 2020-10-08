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

#ifndef LSP_PLUG_IN_R3D_IFACE_BACKEND_H_
#define LSP_PLUG_IN_R3D_IFACE_BACKEND_H_

#include <lsp-plug.in/r3d/iface/version.h>
#include <lsp-plug.in/r3d/iface/types.h>
#include <lsp-plug.in/common/types.h>
#include <lsp-plug.in/common/status.h>

namespace lsp
{
    namespace r3d
    {
        typedef struct backend_metadata_t
        {
            const char *id;             // Enumeration unique identifier
            const char *display;        // Display name
            const char *lc_key;         // Localized display name key
        } backend_metadata_t;

        /**
         * 3D Rendering backend interface, just functions that should be called on
         * a structure instance
         */
        typedef struct backend_t
        {
            /**
             * Destroy backend
             */
            void        (* destroy)(backend_t *_this);

            /**
             * Initialize backend as a native window, all window manipulations
             * should be done by the host
             * @param window native window handle to work with
             * @param out_window pointer to store the created window handle
             * @return status of operation
             */
            status_t    (* init_window)(backend_t *_this, void **out_window);

            /**
             * Initialize backend as an off-screen buffer
             * @return status of operation
             */
            status_t    (* init_offscreen)(backend_t *_this);

            /**
             * @param left the leftmost coordinate of the backend's viewport relative to the parent window
             * @param top the topmost coordinate of the backend's viewport relative to the parent window
             * @param width the width of the backend's viewport
             * @param height the heigh of the backend's viewport
             */
            status_t    (* locate)(backend_t *_this, ssize_t left, ssize_t top, ssize_t width, ssize_t height);

            /**
             * @param left the leftmost coordinate of the backend's viewport relative to the parent window
             * @param top the topmost coordinate of the backend's viewport relative to the parent window
             * @param width the width of the backend's viewport
             * @param height the heigh of the backend's viewport
             */
            status_t    (* get_location)(backend_t *_this, ssize_t *left, ssize_t *top, ssize_t *width, ssize_t *height);

            /**
             * Start rendering on the window
             * @return status of operation
             */
            status_t    (* start)(backend_t *_this);

            /**
             * Complete all pending operations
             * @return status of operation
             */
            status_t    (* sync)(backend_t *_this);

            /**
             * Complete rendering on the window
             * @return status of operation
             */
            status_t    (* finish)(backend_t *_this);

            /**
             * Set transformation matrix
             * @param type transformation matrix type
             * @param m transformation matrix data of 16 floats (column-major)
             * @return status of operation
             */
            status_t    (* set_matrix)(backend_t *_this, matrix_type_t type, const mat4_t *m);

            /**
             * Get transformation matrix
             * @param type transformation matrix type
             * @param m pointer to retrieve transformation matrix data of 16 floats (column-major)
             * @return status of operation
             */
            status_t    (* get_matrix)(backend_t *_this, matrix_type_t type, mat4_t *m);

            /**
             * Set current lighting schema according to passed array of lights
             * @param lights array of lights
             * @param count number of lights per scene
             * @return status of operation
             */
            status_t    (* set_lights)(backend_t *_this, const light_t *lights, size_t count);

            /**
             * Draw data
             * @param buffer buffer data to draw
             * @return status of operation
             */
            status_t    (* draw_primitives)(backend_t *_this, const buffer_t *buffer);

            /**
             * Set the default background color
             * @param color default background color
             * @return status of operation
             */
            status_t    (* set_bg_color)(backend_t *_this, const color_t *color);

            /**
             * Get the default background color
             * @param color pointer to store default background color
             * @return status of operation
             */
            status_t    (* get_bg_color)(backend_t *_this, color_t *color);

            /**
             * Read pixel data, should be in drawing state
             * @param buf target buffer
             * @param stride stride between two rows
             * @param format pixel format
             * @return status of operation
             */
            status_t    (* read_pixels)(backend_t *_this, void *buf, size_t stride, pixel_format_t format);
        } backend_t;
    }
}

#endif /* LSP_PLUG_IN_R3D_IFACE_BACKEND_H_ */
