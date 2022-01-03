// Napisz program, który:
// utworzy potok (funkcją pipe),
// uruchomi podproces, z którym proces nadrzędny będzie komunikował się przez ten potok (funkcja fork),
// proces nadrzędny otworzy plik tekstowy podany w argumencie wywołania programu, a następnie wyśle procesowi potomnemu zawartość tego pliku przez potok,
// proces potomny odczyta dane z potoku, a następnie wyświetli je na standardowym wyjściu dodając znak '#' na początku i końcu każdej odebranej paczki danych.
// Wielkość paczek jest dowolna.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZ 13
#define gora_paczki "\n\n************\n"
#define dol_paczki "************\n\n"

int main(int argc, char *argv[]) 
{
    int potok_fd[2];
    char bufor[BUFSIZ + 1]; //bufor do czytania

    pipe(potok_fd); //tworzymy potok


// potomek
    if (fork() == 0) 
    {
        int buf_paczka_rozmiar = 0;
        while((buf_paczka_rozmiar = read(potok_fd[0], bufor, BUFSIZ)) > 0) //czyta z potoku fo bufora
        {
            write(1, gora_paczki, strlen(gora_paczki));
            write(1, bufor, buf_paczka_rozmiar); // z bufora na stdout
            write(1, dol_paczki, strlen(dol_paczki));
        }
        exit(0);
    }

// rodzic
    FILE * moj_plik = fopen(argv[1], "r"); //zapisujemy do potoku ->
    int plik_paczka_rozmiar;
    while ((plik_paczka_rozmiar = fread(bufor, sizeof(char), BUFSIZ, moj_plik)) > 0) //czyta z pliku do bufora
    {
            bufor[++plik_paczka_rozmiar] = '\0';
            write(potok_fd[1], bufor, strlen(bufor)); //zapis z bufora do potoku
    }
    fclose(moj_plik);
    close(potok_fd[1]);

    return 0;

}