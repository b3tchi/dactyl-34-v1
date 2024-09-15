#!/bin/bash
cd /workspace/zmk-config/ # navigate to the volume
west init --local config  # load from config folder
west update               # update library
