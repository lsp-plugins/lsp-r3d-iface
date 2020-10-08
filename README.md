# lsp-r3d-iface

This is set of 3D rendering backend interfaces.

Provides all necessary data structures and type definitions:
* ```struct factory_t``` for managing the backend metadata and it's creation.
* ```struct backend_t``` for rendering 

Requirements
======

The following packages need to be installed for building:

* gcc >= 4.9
* make >= 4.0

Building
======

To build the library, perform the following commands:

```bash
make config # Configure the build
make fetch # Fetch dependencies from Git repository
make
sudo make install
```

To get more build options, run:

```bash
make help
```

To uninstall library, simply issue:

```bash
make uninstall
```

To clean all binary files, run:

```bash
make clean
```

To clean the whole project tree including configuration files, run:

```bash
make prune
```

