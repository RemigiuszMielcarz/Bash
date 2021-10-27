# Sprawdź wartości priorytetów procesów i ich liczby nice, a następnie przećwicz obniżanie priorytetu pracującego w tle procesu (nice/renice). 
# Czy potrafisz zademonstrować działanie obniżonego liczbą nice priorytetu?
# Podsumuj wynik w raporcie i podaj polecenie obniżania priorytetu procesu.

nice -n 15 ./L3_Z5.sh
renice -n liczba -p nr procesu