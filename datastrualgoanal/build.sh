#!/bin/sh
ori_path=`pwd`
cd ./build
cmake .
if [ $1='r' ]; then
  make clean
fi
make
cd $ori_path
