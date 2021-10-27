#!/bin/bash
zm=$(w | grep $1 | wc -l)
echo $zm
if [ $zm -ne 0 ]
then
    echo $1 jest zalogowany!
else
    echo $1 nie jest zalogowany!
fi
