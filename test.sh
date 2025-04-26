#!/bin/bash

mkdir -p ./test/salida

for i in {1..4}
do
    dos2unix "./test/testeo/test$i.txt"
    dos2unix "./test/esperado/test$i.txt"
    ./main.out < "./test/testeo/test$i.txt" > "./test/salida/test$i.txt"
    if diff -q "./test/salida/test$i.txt" "./test/esperado/test$i.txt" > /dev/null; then
        echo "Test aprobado"
    else 
        echo "Test rechazado"
        diff "./test/salida/test$i.txt" "./test/esperado/test$i.txt"
    fi
done
