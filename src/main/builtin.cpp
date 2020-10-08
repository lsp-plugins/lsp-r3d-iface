/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-iface
 * Created on: 8 окт. 2020 г.
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

#include <lsp-plug.in/r3d/iface/builtin.h>

namespace lsp
{
    namespace r3d
    {
        Factory *Factory::pList = NULL;

        Factory::Factory(factory_t *factory)
        {
            pFactory    = factory;
            pNext       = pList;

            pList       = this;
        }

        Factory::~Factory()
        {
            pFactory    = NULL;
            pNext       = NULL;

            if (pList == this)
                pList = NULL;
        }
    }
}


