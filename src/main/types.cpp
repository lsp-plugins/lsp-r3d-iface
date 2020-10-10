/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-iface
 * Created on: 9 окт. 2020 г.
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

#include <lsp-plug.in/r3d/iface/types.h>

namespace lsp
{
    namespace r3d
    {
        void init_buffer(buffer_t *buf)
        {
            buf->model.m[0]         = 1.0f;
            buf->model.m[1]         = 0.0f;
            buf->model.m[2]         = 0.0f;
            buf->model.m[3]         = 0.0f;

            buf->model.m[4]         = 0.0f;
            buf->model.m[5]         = 1.0f;
            buf->model.m[6]         = 0.0f;
            buf->model.m[7]         = 0.0f;

            buf->model.m[8]         = 0.0f;
            buf->model.m[9]         = 0.0f;
            buf->model.m[10]        = 1.0f;
            buf->model.m[11]        = 0.0f;

            buf->model.m[12]        = 0.0f;
            buf->model.m[13]        = 0.0f;
            buf->model.m[14]        = 0.0f;
            buf->model.m[15]        = 1.0f;

            buf->type               = PRIMITIVE_NONE;
            buf->flags              = 0;
            buf->width              = 1.0f;
            buf->count              = 0;

            buf->vertex.data        = NULL;
            buf->vertex.stride      = 0;
            buf->vertex.index       = NULL;

            buf->normal.data        = NULL;
            buf->normal.stride      = 0;
            buf->normal.index       = NULL;

            buf->color.data         = NULL;
            buf->color.stride       = 0;
            buf->color.index        = NULL;
            buf->color.dfl.r        = 0.5f;
            buf->color.dfl.r        = 0.5f;
            buf->color.dfl.r        = 0.5f;
            buf->color.dfl.a        = 0.0f;
        }
    }
}



