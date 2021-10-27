#!/bin/bash

# Zgodnie z przewidywaniami wyświetlił się komunikat o niemożności otwarcia zablokowanego pliku1. 
# System zapytał też, podczas linkowania, czy ma pominąć zabezpieczenie 44.

touch plik1
touch plik2
mkdir katalog1
mv plik2 plik_zmieniony
cp ./plik_zmieniony ./katalog1/plik_przeniesiony
chmod u-rwx plik1
cat plik1
rm plik1
touch plik3
touch plik4
ln plik3 plik4