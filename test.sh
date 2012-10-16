#!/bin/bash -ex
convert $1.pnm $1.xbm
./compile.sh $1
./a.out | pnmtoplainpnm > /tmp/tmp
set +x
diff /tmp/tmp $1.pnm | head -n5
if [ ${PIPESTATUS[0]} -ne 0 ]; then exit 1; fi
rm $1.xbm
rm /tmp/tmp
echo "SUCCESS!"
