# Poleceniem mknod utwórz potok nazwany (FIFO). 
# W co najmniej czterech okienkach wywołaj równoczesne pisanie do, i równoczesne czytanie z tego potoku przez wiele procesów (polecenie cat).

# Sprawdź (i podaj w raporcie) jak system rozdziela dane z pliku procesom o współdzielonym dostępie do tego potoku?

# Zabijając na przemian procesy piszące/czytające, zaobserwuj, kiedy proces cat czytający z potoku czeka na więcej danych, a kiedy kończy pracę. 
# Analogicznie, kiedy proces piszący czeka w gotowości do dalszego pisania na potoku, a kiedy samoistnie kończy pracę. Podsumuj w raporcie. 

# mknod FIFO p # Utworzenie pliku FIFO

while :
do
    echo "L3_Z4 Working"
    echo tekst > FIFO
    cat zadanie4.txt < FIFO
    sleep 1
done