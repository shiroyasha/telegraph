#!/usr/bin/env bash

sudo apt-get install libgtest-dev cmake -y

cd /usr/src/gtest

sudo cmake CMakeLists.txt
sudo make

sudo cp *.a /usr/lib
