#!/bin/sh

qmk generate-compilation-database -kb splitkb/aurora/lily58 -km luuklelifeld
cp ~/qmk_firmware/compile_commands.json ./
