#!/bin/sh

srcpath=`pwd`

rm -rf build bin lib
mkdir build
cd build

cmake ${srcpath}
