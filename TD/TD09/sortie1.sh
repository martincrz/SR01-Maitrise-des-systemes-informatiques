#!/bin/bash

./sortie1
var=$?

if [ $var -eq 1 ];
then 
echo "Pas compris entre 5 et 10"
else
echo "Compris entre 5 et 10"
fi
