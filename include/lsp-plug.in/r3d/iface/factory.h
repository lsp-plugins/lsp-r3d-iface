/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-iface
 * Created on: 24 апр. 2019 г.
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

#ifndef LSP_PLUG_IN_R3D_IFACE_FACTORY_H_
#define LSP_PLUG_IN_R3D_IFACE_FACTORY_H_

#include <lsp-plug.in/r3d/iface/version.h>

#include <lsp-plug.in/r3d/iface/backend.h>
#include <lsp-plug.in/r3d/iface/types.h>

#define LSP_R3D_FACTORY_FUNCTION_NAME           "lsp_r3d_factory"
#define LSP_R3D_FACTORY_FUNCTION_HEADER(index)  ::lsp::r3d::factory_t *lsp_r3d_factory(int index)

namespace lsp
{
    namespace r3d
    {
        /**
         * Factory for obtaining 3D rendering backend metadata and
         * constructing 3D backend instance
         */
        typedef struct factory_t
        {
            /**
             * Get backend metadata
             * @param id backend identifier, starting with 0
             * @return status of operation or NULL if there is no such backend
             */
            const backend_metadata_t        *(* metadata)(factory_t *_this, size_t id);

            /**
             * Create backend
             * @param id backend identifier
             * @return status of operation
             */
            backend_t                       *(* create)(factory_t *_this, size_t id);

        } factory_t;

        /**
         * Factory function prototype
         * @param index the enumeration factory number starting with 0
         * @return pointer to the factory function or NULL if there are no more items in enumeration
         */
        typedef factory_t *(* factory_function_t)(int index);
    }
}

#endif /* LSP_PLUG_IN_R3D_IFACE_FACTORY_H_ */
