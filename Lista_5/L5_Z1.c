// strace [app] - polecenie do sledzenia wywolan systemowych oraz wywolania sygnalow. 
// Moze sluzyc jako narzedzie diagnostyczne np.do przesledzenia czy w programie wystepuja wyscigi.
// Wyjscie polecenia ma postac:
// nazwa wywolania systemowego (argumenty) = zwracana wartosc
// Sygnaly sa dekodowane do struktury siginfo.
// Jesli wywolanie systemowe zostaje wstrzymane podczas dzialania programu pojawia sie znacznik- ¿
// unfinished, pozniej przy przywracaniu wywolania znacznik -¿resumed.
// Wskazniki na struktury sa wyluskiwane wraz z kazdym polem struktury (pokazywane sa wszystkie wartosci).
// Pomocne wywolania:
// strace -e trace=[nazwa polecenia systemowego] [program] - wyszukanie konkretnego polecenia
// systemowego, mozliwosc wyszukiwania kilku polecen jednoczesnie
// strace -e signal=[nazwa sygnalu] [program] - wyszukuje okreslony zestaw sygnalow
// strace -p - strace dla konkretnego pid
// strace -t - dodaje moment wywolania / mozna tez -r co daje lepszy podglad
// strace -T - dodaje czas trwania wywolania
// strace -c - dodaje ilosc czasu na dane wywolanie systemowe

#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     printf("Hello, world.\n");


//     return 0;
// }

// execeve() - wykonuje program wskazywany przez filename (./a.out)
// brk(NULL) = 0xXXXXXXX - podaje informacje gdzie kończy się stos pamięci
// close () - zamyka deskryptor
// mprotect - ustawia ochronę obszarów pamięci
// write() - wpisuje do deskryptora wartość bufora i zwraca ilość wpisanych znaków (14 w printf).

// (d) Zmodyfikuj napisany program aby witał on użytkownika jego identyfikatorem symbolicznym uzyskanym jako wartość zmiennej środowiskowej LOGNAME (funkcja getenv). 
// Ponownie uruchom program przez strace. Jaki napis został wyświetlony przez funkcję systemową? Gdzie podziało się wywołanie getenv?

// Uruchom tę wersję programu przez ltrace i porównaj z wynikami z strace. Czym różnią się otrzymane wyniki? 
// Jaki wniosek można sformułować odnośnie śledzenia wykonywanych programów.

int main()
{
    printf("IDENTYFIKATOR: %s\n", getenv("LOGNAME"));


    return 0;
}

// strace -o plik.txt -v -e execve ./a.out