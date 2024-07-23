# DolphiNX - A GameCube and Wii Emulator for the Nintendo Switch™️

[Homepage](https://dolphin-emu.org/) | [Project Site](https://github.com/dolphinx-emu/dolphinx) | [Buildbot](https://dolphin.ci/) | [Forums](https://forums.dolphin-emu.org/) | [Wiki](https://wiki.dolphin-emu.org/) | [GitHub Wiki](https://github.com/dolphin-emu/dolphin/wiki) | [Issue Tracker](https://bugs.dolphin-emu.org/projects/emulator/issues) | [Coding Style](https://github.com/dolphin-emu/dolphin/blob/master/Contributing.md) | [Transifex Page](https://app.transifex.com/dolphinemu/dolphin-emu/dashboard/)

DolphiNX is an emulator for running GameCube and Wii games on the Nintendo Switch™️.
It's licensed under the terms of the GNU General Public License, version 2 or later (GPLv2+).

## Building 
You must have:
- [devkitpro](https://devkitpro.org/wiki/Getting_Started) installed with the `switch-dev` tools installed
- Latest [CMake](https://cmake.org/)

Then simply run (from devkitpro's CLI on Windows, or from any shell on Unix-like platforms):
```shell
mkdir build
cd build
${DEVKITPRO}/portlibs/switch/bin/aarch64-none-elf-cmake -DCMAKE_BUILD_TYPE=Release -S ..
make
```
Et voilà!

## Uninstalling
Simply remove the compiled program from your SD Card/wherever you keep homebrew for your Switch.
