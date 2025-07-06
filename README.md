# dactyl-34-v1

modification of pro-micro dactyl v0 adjusted for the 34keys

## info how for custom shift

<https://getreuer.info/posts/keyboards/custom-shift-keys/index.html>

## another approach derived from miryoku (Prefered)

<https://peppe.rs/posts/programming_on_34_keys/>

## list of default keycodes

<https://docs.qmk.fm/#/keycodes_basic>

## home row mod article

<https://precondition.github.io/home-row-mods>

## other resources

### ben vallack using another interesting concept of tap dance TD()

<https://github.com/benvallack/34-QMK-Ferris-Sweep/blob/main/keymap.c>

## repository files overivew

- zmk-config/boards/shileds/popup
  - Kconfig.defconf *general name and split setup*
  - Kconfig.shield *decision if left or ringht*
  - dusk.conf *only sleep option*
  - popup.dtsi *rows and map*
  - popup.keymap *keymap*
  - popup.zmk.yml *config*
  - popup_left.conf *dummy empty*
  - popup_left.overlay *column mapping*
  - popup_right.conf *dummy empty*
  - popup_right.overlay column mapping

## preparing docker

### preparing files

```nu
# rm -rf ./workspace
mkdir ./workspace

cp -ruv ./zmk/src/zmk-config/ ./workspace/
cp -ruv ./zmk/ci/ ./workspace/
```

### run initial setup

```nu
(docker run -it -v
 ./workspace:/workspace
 zmkfirmware/zmk-build-arm:3.5
 /bin/bash /workspace/ci/init.sh
)
```

#### rebuilding only firmware changes

- when doing changes in copying repeat copying source code part and repeat steps starting with build

```nu
cp -ruv ./zmk/src/zmk-config/config ./workspace/zmk-config/.config
```

### build parts

```nu
(docker run -it -v
 ./workspace:/workspace
 zmkfirmware/zmk-build-arm:3.5
 /bin/bash /workspace/ci/build.sh
)
```

### deploying firmware

- connect keyboard with usb
- add keyboard to flash mode in case of nano or arduino it's double-click reset
- *manually mount nano in f.e. thunnar*
- flash with build firmwares

```nu
cp ./workspace/output/popup_left.uf2 /run/media/jan/NICENANO/
```

```nu
cp ./workspace/output/popup_right.uf2 /run/media/jan/NICENANO/
```

### mounting keyboard

ensure `xorg-xinput` installed
tbd wayland config

nu query to extract id

```nu
let keyboard_id = (
 xinput list 
 | lines
 | where ($it =~ 'Pop-Up') 
 | where ($it =~ 'keyboard') 
 | split row -r '\s+' 
 | where ($it =~ 'id=') 
 | split row '=' 
 | get 1
)

setxbmap -device $keyboard_id -layout us
```

#### get id of the manually

```nu
#list connected devices
xinput list

#output list in the output is id 17 where slave keyboard
#> Virtual core pointer
#> ...
#> ↳ ZMK Project Pop-Up Keyboard id=14 [slave pointer (2)]
#> Virtual core keyboard
#> ...
#> ↳ ZMK Project Pop-Up Keyboard id=17 [slave keyboard (3)]

setxbmap -device 17 -layout us
```

## install docker manjaro/arch pacman

```nu

sudo pacman -Syu
sudo pacman -S docker
sudo systemctl enable docker.service
sudo systemctl start docker.service
sudo usermod -aG docker $USER

```

# Appendix local approach notes

## installing zmk

```ps1
powershell -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://zmk.dev/setup.ps1'))"
```

```bash
bash -c "$(curl -fsSL https://zmk.dev/setup.sh)"
```

pick 40) Kyria Rev v3 [details](https://zmk.dev/docs/hardware#composite)
pick 10) nice!nano v2

## zmk prerequisites

```bash
scoop install cmake
```

## installing zmk dev

```bash
git clone https://github.com/zmkfirmware/zmk.git
cd zmk
python -m venv .venv
```

> [!NOTE]
> nushell venv not supported windows workaround

```bash

powershell
.venv\Scripts\Activate.ps1
nu

```

## updating environment

```bash

pip install west
west init -l app/
west update
west zephyr-export
# additional dependecies
pip install -r zephyr/scripts/requirements-base.txt

```

## building

```bash

cp -r

```

## wsl

```bash

wsl -d Ubuntu-zmk -u jan
west build -s . -b nice_nano_v2 -- -DZMK_CONFIG=/workspace/zmk-config/config/ -DSHIELD=popup-left

```
