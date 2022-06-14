@echo off

mkdir build
pushd build
cl -FC -Zi ../*.c
popd
