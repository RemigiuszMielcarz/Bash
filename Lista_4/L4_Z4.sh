#!/bin/bash

# Uruchom program/skrypt przechwytujący oraz ignorujący wybrane sygnały. Następnie sprawdź tablicę akcji przypisanych poszczególnym sygnałom.

# Robimy na diablo
# chmod +x L4_Z4.sh
# Odpalamy ./L4_Z4.sh

# w innym terminalu 
# ps -U rmielcar
# cat L4_Z4.sh
# 9 sygnałów przechwyconych
# psig -n PID_L4_Z4.sh

# Przykładowo FPE o numerze 8 jest poza trapem i jest ustawione na default w psig.

while true; do
    #trap 'echo "Polecenie trap wykonane"' 2 9 15 8
    trap 'echo "Polecenie trap wykonane"' 1 2 3 4 5 9 10 11 12
    echo "Jest godzina: $(date +%T)"
    sleep 2
done
