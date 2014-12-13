#!/bin/bash

mkdir -p build
pushd build
c++ ../code/handmadehero.cpp -o handmadehero -g `sdl2-config --cflags --libs`
