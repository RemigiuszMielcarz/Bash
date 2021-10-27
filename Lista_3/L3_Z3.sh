#!/bin/bash

# Uruchom potok co najmniej trzech poleceń działających przez jakiś zauważalny czas. 
# Mogą to być odpowiednio dobrane polecenia systemowe, lub samodzielnie napisane skrypty. 
# Sprawdź poleceniem ps i odpowiedz jakie zachodzi pokrewieństwo między tymi procesami (jeśli w ogóle zachodzi). 

# KOMENDA_0 | KOMENDA_1 | ... | KOMENDA_N
#     stdout z komendy 0 jest podawane na stdin komendy 1, itp.

while [1]
do 
    echo "Cokolwiek"
    sleep 2
done

#     1 terminal
#chmod +x L3_Z3.sh
#./L3_Z3.sh | cat | cat
#Cokolwiek
#Cokolwiek
#Cokolwiek

#     2 terminal
#ps -lu rmielcar
#wywołania cat mają inne PID, PPID takie same, taki sam terminal TTY

