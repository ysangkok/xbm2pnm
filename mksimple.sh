#!/bin/sh -ex
convert $1 -monochrome /tmp/monochrome.pnm
pnmtoplainpnm /tmp/monochrome.pnm
