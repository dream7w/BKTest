#!/bin/sh
ori_path=`pwc`
cd ./build
cmake .
make
cd $ori_path
