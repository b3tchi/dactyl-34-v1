#!/bin/bash
build_part() {
	west build -s app -b nice_nano_v2 -- \
		-DZMK_CONFIG=/workspace/zmk-config/config/ \
		-DSHIELD="$1"
	mv -fv ./build/zephyr/zmk.uf2 "../../output/$1.uf2" # copy binary to output
	rm -rf ./build                                      # cleanup /workspace/zmk-config/zmk/build
}

cd /workspace/zmk-config/ # navigate to the volume
west zephyr-export        # needed
mkdir -p ./../output      # create /workspace/output
cd ./zmk                  # go to /workspace/zmk-config/zmk
build_part popup_left     # build left with function build_part
build_part popup_right    # build right with function build_part
build_part settings_reset # build special part to unpair halfes
