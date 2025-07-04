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

preparing files

```nu
# rm -rf ./workspace
mkdir ./workspace

cp -ruv ./zmk/src/zmk-config/ ./workspace/
cp -ruv ./zmk/ci/ ./workspace/
```

run initial setup

```nu
(docker run -it -v
 ./workspace:/workspace
 zmkfirmware/zmk-build-arm:3.5
 /bin/bash /workspace/ci/init.sh
)
```

build parts

```nu
(docker run -it -v
 ./workspace:/workspace
 zmkfirmware/zmk-build-arm:3.5
 /bin/bash /workspace/ci/build.sh
)
```

## install docker manjaro/arch pacman

```nu
cp ./workspace/output/popup_left.uf2 /run/media/jan/NICENANO/
```

```nu
cp ./workspace/output/popup_right.uf2 /run/media/jan/NICENANO/
```

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
