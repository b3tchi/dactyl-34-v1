#!/bin/bash
root_path="$(realpath "$(dirname $0)/..")"

#check layout
if [[ -z "$1" ]]; then
	layout=default
else
	layout="$1"
fi

#check layout
if [[ -z "$2" ]]; then
	action=compile
else
	action="$2"
fi

# echo "$root_path"
repo_name="$(basename -s .git $(git config --get remote.origin.url))"

run_path="$HOME/tmp/$repo_name/qmk_firmware"

# rm -rf "$run_path"
# mkdir -p "$run_path"

if [[ ! -d "$run_path" ]]; then
	qmk setup --home "$run_path"
fi

ln -s "$run_path" "$root_path/bin"

#copy current item to folder
rm -rf "$root_path/bin/keyboards/handwired/dactyl_promicro"

#copy current content
cp -rv "$root_path/src" -T "$root_path/bin/keyboards/handwired/dactyl_promicro"

#build
cd "$root_path/bin"

qmk $action -kb handwired/dactyl_promicro -km "$layout"
