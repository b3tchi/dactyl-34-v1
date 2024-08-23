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

## installing zmk

```ps1

powershell -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://zmk.dev/setup.ps1'))"

```

pick 40) Kyria Rev v3 [details](https://zmk.dev/docs/hardware#composite)
pick 10) nice!nano v2

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
