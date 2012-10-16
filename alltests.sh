#!/bin/bash -ex

for ((i = 70 ; i < 76 ; i++ ))
do
pnmcut 0 0 $i $i < logo.pnm | pnmtoplainpnm | tee logo2$i.pnm > /dev/null
./test.sh logo2$i
rm logo2$i.pnm
done

for i in logo:
do
./mksimple.sh $i > testimg.pnm
./test.sh testimg
done
