# **Digital Casting System APP**

![GitHub - License](https://img.shields.io/badge/License-MIT-black.svg)
[![vcpkg version](https://img.shields.io/badge/vcpkg-lastest-white)]
[![glfw version](https://img.shields.io/badge/glfw-3.3.9-black)](https://github.com/glfw/glfw)
[![glad version](https://img.shields.io/badge/glad-0.1.36-white)](https://github.com/Dav1dde/glad?tab=readme-ov-file)
[![imgui version](https://img.shields.io/badge/imgui-1.90.4-black)](https://github.com/ocornut/imgui)
[![cmake version](https://img.shields.io/badge/cmake-3.20.1-black)](https://cmake.org/)
[![cpp version](https://img.shields.io/badge/c++-20-black)]()

## Requirements

#### Platform:

- [Windows 10](https://www.microsoft.com/en-us/software-download/windows10)
- [Ubuntu 22.04](https://ubuntu.com/download/desktop)


## Installation

#### Windows

```bash
git clone https://github.com/USI-FMAA/digital_casting_app.git
git clone --recurse-submodules -j8 https://github.com/microsoft/vcpkg

# install package manager
.\VCPKG\bootstrap-vcpkg.bat

# initialize and build app
.\package-install.bat
```

#### MacOS/Ubuntu

```bash
git clone https://github.com/USI-FMAA/digital_casting_app.git
git clone --recurse-submodules -j8 https://github.com/microsoft/vcpkg

# install package manager
./VCPKG/bootstrap-vcpkg.sh

# install package
./package-install.sh

# initialize and build app
./init-setup-osx.sh

# test app

```

## Development

#### Windows

```bash
# update the package manger
git submodule add https://github.com/microsoft/vcpkg VCPKG

# install package
.\VCPKG\bootstrap-vcpkg.bat

# initialize and build app
.\package-install.bat

# test app
.\build\debug\dcs_app.exe

```

#### MacOS/Ubuntu

```bash
git clone https://github.com/USI-FMAA/digital_casting_app.git
git clone --recurse-submodules -j8 https://github.com/microsoft/vcpkg

# install package manager
./VCPKG/bootstrap-vcpkg.sh

# install package
./package-install.sh

# initialize and build app
./init-setup-osx.sh

# test app
./build/debug/dcs_app

```
## Package Version

package architecture:


## Credits

This package was created by [WeiTing Chen](https://github.com/WeiTing1991) at [USI-FMAA](https://github.com/USI-FMAA), [PCBM ETHZ](https://ifb.ethz.ch/pcbm), and [ETHZurich DFab](https://dfab.ch/).
