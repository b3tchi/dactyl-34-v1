# popup-42-v1

zmk based split keyboard inpired by dactyl renamed to pop-up butterfly with dvorak layout

## repository files overivew

- zmk-config/boards/shileds/popup
  - Kconfig.defconf *general name and split setup*
  - Kconfig.shield *decision if left or ringht*
  - dusk.conf *only sleep option*
  - popup.dtsi *rows and map*
  - popup.keymap *keymap* [kycodes](https://zmk.dev/docs/keymaps/list-of-keycodes)
  - popup.zmk.yml *config*
  - popup_left.conf *dummy empty*
  - popup_left.overlay *column mapping*
  - popup_right.conf *dummy empty*
  - popup_right.overlay column mapping

## preparing docker

### preparing files

```nu
# rm -rf ./workspace
mkdir ./workspace/zmk-config/

# cp -ruv ./zmk/src/zmk-config/ ./workspace/
cp -ruv ./zmk/ci/ ./workspace/
```

### run initial setup

- for initial setup
```nu
cp -rfv ./zmk/src/zmk-config/config ./workspace/zmk-config/config
```
```nu
(docker run -it -v
 ./workspace:/workspace
 zmkfirmware/zmk-build-arm:3.5
 /bin/bash /workspace/ci/init.sh
)
```

#### rebuilding only firmware changes

- when doing changes in copying repeat copying source code part and repeat steps starting with build

- for overwritting firmwared
```nu
cp -rfv ./zmk/src/zmk-config/config ./workspace/zmk-config
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
mkdir ./nano
sudo mount -t vfat -o 'rw,nosuid,nodev,relatime,uid=1000,gid=1000,fmask=0022,dmask=0022,codepage=437,iocharset=ascii,shortname=mixed,showexec,utf8,flush,errors=remount-ro,uhelper=udisks2' /dev/sda $"('./nano' | path expand)"
```

```nu
sudo cp $"('./workspace/output/popup_right.uf2' | path expand)" $"('./nano' | path expand)"
sudo umount /dev/sda
```

```nu
sudo cp $"('./workspace/output/popup_left.uf2' | path expand)" $"('./nano' | path expand)"
sudo umount /dev/sda
```

*** manually mounted

```nu
cp ./workspace/output/popup_left.uf2 /run/media/jan/NICENANO/
```

```nu
cp ./workspace/output/popup_right.uf2 /run/media/jan/NICENANO/
```

### mounting keyboard

ensure `xorg-xinput` installed
tbd wayland config

set notebook keyboard as dvorak (part of i3 config)
```nu
setxkbmap -device (xinput list --id-only 'keyboard:AT Translated Set 2 keyboard') -layout us -variant dvorak
```

set pop-up keyboard as qwerty as dvorak as directly in the map
```nu
setxkbmap -device (xinput list --id-only 'keyboard:ZMK Project Pop-Up Keyboard') -layout us -variant qwerty
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

### reset keyboard halves pairing
Dual split keyboards are automatically try to pair themself, when not yet paired and resetted simultanously. This pairing is stored somewhere in board and not overwritten with
flashing new versions. To unpair, both sides have to be flashed by special image and then re-flashed again with the existing board images.

```nu
cp ./workspace/output/settings_reset.uf2 /run/media/jan/NICENANO/
```

## install docker manjaro/arch pacman

```nu

sudo pacman -Syu
sudo pacman -S docker
sudo systemctl enable docker.service
sudo systemctl start docker.service
sudo usermod -aG docker $USER

```

## Appendix A local zmk installing approach notes
```ps1
powershell -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://zmk.dev/setup.ps1'))"
```

```bash
bash -c "$(curl -fsSL https://zmk.dev/setup.sh)"
```

pick 40) Kyria Rev v3 [details](https://zmk.dev/docs/hardware#composite)
pick 10) nice!nano v2

### zmk prerequisites

```bash
scoop install cmake
```

### installing zmk dev

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

### updating environment

```bash

pip install west
west init -l app/
west update
west zephyr-export
# additional dependecies
pip install -r zephyr/scripts/requirements-base.txt

```

### building

```bash

cp -r

```

### wsl

```bash

wsl -d Ubuntu-zmk -u jan
west build -s . -b nice_nano_v2 -- -DZMK_CONFIG=/workspace/zmk-config/config/ -DSHIELD=popup-left

```

## Appendix B notes to original 34 key variant with homerow mod
modification of pro-micro dactyl v0 adjusted for the 34keys

### info how for custom shift

<https://getreuer.info/posts/keyboards/custom-shift-keys/index.html>

### another approach derived from miryoku (Abandoned)
unordered listginally qmk with	34 keys and homerow mode 

<https://peppe.rs/posts/programming_on_34_keys/>

### list of default keycodes qmk

<https://docs.qmk.fm/#/keycodes_basic>

### home row mod article

<https://precondition.github.io/home-row-mods>

### ben vallack using another interesting concept of tap dance TD()

<https://github.com/benvallack/34-QMK-Ferris-Sweep/blob/main/keymap.c>

