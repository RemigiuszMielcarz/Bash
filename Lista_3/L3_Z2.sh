# W jednym okienku terminala uruchom hierarchię co najmniej trzech procesów, tzn. procesy A, który uruchomi proces potomny B, który uruchomi proces potomny C. 
# Mogą to być kolejno uruchamiane interpretery poleceń, albo uruchamiające się kolejno skrypty lub programy. 
# W innym oknie terminala sprawdź programem ps zależności potomków i rodziców w utworzonej hierarchii.
# Poleceniem kill zabij proces w środku tej hierarchii (B). 
# Sprawdź poleceniem ps co pozostało z pierwotnych procesów, i czy osierocony proces zostanie poprawnie adoptowany przez proces init.

# Skrypty mają za zadania uruchomić się wzajemnie a następnie poczekać 100 sekund po czym zostają zakończone. 
# Proces init nie pojawił się na liście procesów.

./sh1.sh

# ps -a --forest = wyświetlenie drabinkowe

# ps -u 
# kill -9 nrprocesu