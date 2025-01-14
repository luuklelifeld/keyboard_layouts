#!/bin/sh

script_dir="$(dirname $0)"

if [ $script_dir = "." ]
then
    script_dir=""
else
    script_dir="/$script_dir"
fi

ln -s "$script_dir" ~/qmk_firmware/keyboards/splitkb/aurora/lily58/keymaps/luuklelifeld
