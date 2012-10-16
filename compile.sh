#!/bin/bash -e
f=$1
g=$(echo -e "$(cat $f.xbm)\n${f}_width" | cpp | tail -n1)
h=$(echo -e "$(cat $f.xbm)\n${f}_height" | cpp | tail -n1)
gcc -Os -std=c99 -D XBM_FILE=$f -D XBM_BITS=${f}_bits \
	-D XBM_WIDTH=$g\
	-D XBM_ARR_SIZE="sizeof(${f}_bits)" \
	-D XBM_HEIGHT=$h\
	xbm2pnm.c
