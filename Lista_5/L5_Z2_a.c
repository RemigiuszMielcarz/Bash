// truss 
// -c Raczej liczy śledzone wywołania systemowe, usterki i sygnały niż wyświetlanie śledzenia linia po linii. 
// Raport podsumowujący jest tworzony po zakończeniu śledzonego polecenia
// -r Pokazuje pełną zawartość bufora we/wy dla każdego read() na dowolnym z podanych deskryptorów plików.
// Dane wyjściowe są sformatowane 32 bajty na linię
// -s Sygnały do ​​śledzenia lub wykluczenia. Sygnały wyszczególnione na liście oddzielonej przecinkami są śledzone. 
// Wyjście śledzenia zgłasza odbiór każdego określonego sygnału, nawet jeśli sygnał jest ignorowany (nie blokowany).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Hello world\n");
    return 0;
}

// truss ./a.out - odpowiada za to write