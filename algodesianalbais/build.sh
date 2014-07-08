#!/bin/sh
ori_path=`pwd`
cd ./build
cmake .
make
cd $ori_path
