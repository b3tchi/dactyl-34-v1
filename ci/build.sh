#!/bin/bash
root_path="$(realpath "$(dirname $0)/..")"

# echo "$root_path"
repo_name="$(basename -s .git `git config --get remote.origin.url`)"

run_path="$HOME/tmp/$repo_name/qmk_firmware"

# rm -rf "$run_path"
# mkdir -p "$run_path"

if [[ ! -d "$run_path" ]]; then
  # echo "$root_path"
  qmk setup --home "$run_path"
fi

ln -s "$run_path" "$root_path/bin"
