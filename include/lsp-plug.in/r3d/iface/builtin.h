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

#ifndef LSP_PLUG_IN_R3D_IFACE_BUILTIN_H_
#define LSP_PLUG_IN_R3D_IFACE_BUILTIN_H_

#include <lsp-plug.in/r3d/iface/version.h>

#include <lsp-plug.in/common/types.h>
#include <lsp-plug.in/r3d/iface/factory.h>

namespace lsp
{
    namespace r3d
    {
        /**
         * This class allows to automatically register built-in factory
         */
        class LSP_SYMBOL_HIDDEN Factory
        {
            private:
                Factory & operator = (const Factory &);

            private:
                static Factory *pList;

                factory_t      *pFactory;
                Factory        *pNext;

            public:
                explicit Factory(factory_t *factory);
                ~Factory();

            public:
                static inline Factory      *list() { return pList;  }
                static factory_t           *enumerate(int index);

                inline Factory             *next() { return pNext;  }
        };

        /**
         * Macro for simplifying definition of factory export
         */
        #define LSP_R3D_BUILTIN_FACTORY(symbol, factory)   \
            LSP_SYMBOL_HIDDEN \
            ::lsp::r3d::Factory symbol(factory);

        /**
         * The implementation of factory function that uses builtin factory
         * descriptor to enumerate all possible factories
         */
        #define LSP_R3D_BULTIN_FACTORY_FUNCTION \
            LSP_R3D_FACTORY_FUNCTION_HEADER(index) \
            { \
                return Factory::enumerate(index); \
            }

    }
}

#endif /* LSP_PLUG_IN_R3D_IFACE_BUILTIN_H_ */
