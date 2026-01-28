#!/bin/bash

pkill -u "$USER" -x worker
pkill -u "$USER" -x controller
rm runscript.log

./controller 67656 >>runscript.log 2>&1 &
sleep 1
x=0
while [ $x -lt 5 ]; do
  ./worker 67656 >>runscript.log 2>&1 &
  ((x++))
done
