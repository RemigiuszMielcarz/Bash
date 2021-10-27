#!/bin/bash

# Zmodyfikuj napisany przykładowy skrypt tak by wykonywał operacje na swoich argumentach: $1, $2, $3, ...
# Jeśli skrypt wykonuje operacje na plikach, to
# spróbuj przerobić go tak, żeby dla każdego argumentu zadawał pytanie (poleceniem echo), czy wykonać daną operację czy nie.

# Skrypt tworzący nowy katalog (o nazwie zadanej argumentem 1) i zamieniający rozszerzenia wszystkich plików z zadanego argumentem 2 na zadane argumentem 3.

if [ -e $1 ]; then
    echo "$1 juz istnieje!"
else
    echo "Czy utworzyc nowy katalog '$1'?"
    read zgoda
    if [ "$zgoda" = "tak" ]; then
        mkdir "$1"
        echo "Pomyslnie utworzono plik"
    fi
fi

rozszerzenie=$($2 | cut -d '.' -f 2)
for nazwa in $(rozszerzenie); do
    echo "Czy zamienic rozszerzenie pliku z '$2' na '$3'?"
    read zgoda
    if [ "$zgoda2" = "tak" ]; then
        rename 's/$2/$3/g' $nazwa
    fi

done