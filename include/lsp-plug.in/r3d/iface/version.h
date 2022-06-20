/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-iface
 * Created on: 3 мая 2020 г.
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

#ifndef LSP_PLUG_IN_R3D_IFACE_VERSION_H_
#define LSP_PLUG_IN_R3D_IFACE_VERSION_H_

#define LSP_R3D_IFACE_MAJOR             1
#define LSP_R3D_IFACE_MINOR             0
#define LSP_R3D_IFACE_MICRO             2

#ifdef LSP_R3D_IFACE_BUILTIN
    #define LSP_R3D_IFACE__EXPORT
    #define LSP_R3D_IFACE__CEXPORT
    #define LSP_R3D_IFACE_IMPORT            LSP_SYMBOL_IMPORT
    #define LSP_R3D_IFACE_CIMPORT           LSP_CSYMBOL_IMPORT
#else
    #define LSP_R3D_IFACE_EXPORT            LSP_SYMBOL_EXPORT
    #define LSP_R3D_IFACE_CEXPORT           LSP_CSYMBOL_EXPORT
    #define LSP_R3D_IFACE_IMPORT            LSP_SYMBOL_IMPORT
    #define LSP_R3D_IFACE_CIMPORT           LSP_CSYMBOL_IMPORT
#endif

#define LSP_R3D_IFACE_VERSION_FUNC_NAME     "lsp_r3d_iface_version"

#define LSP_R3D_IFACE_DEF_VERSION_FUNC   \
    const ::lsp::version_t *lsp_r3d_iface_version() \
    { \
        static const ::lsp::version_t v=LSP_DEF_VERSION(LSP_R3D_IFACE_MAJOR, LSP_R3D_IFACE_MINOR, LSP_R3D_IFACE_MICRO); \
        return &v; \
    }

#endif /* LSP_PLUG_IN_R3D_IFACE_VERSION_H_ */
