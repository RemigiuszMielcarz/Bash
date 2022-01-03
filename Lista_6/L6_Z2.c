// Zmodyfikuj program z punktu 1:
// proces nadrzędny zamiast pliku graficznego ma przesyłać plik graficzny (JPEG lub PNG),

// proces potomny zamiast odczytywać bezpośrednio z potoku wykona przekierowanie zawartości potoku na standardowe wejście (funkcje close i dup), 
// a następnie uruchomi program (jedna z funkcji exec*) wyświetlający obrazek pobrany z tego wejścia (deskryptora 0).

// Jako program wyświetlający obrazki można zastosować program display należący do pakietu Image Magick. 
// Przydatnym programem wyświetlającym obrazki jest również xv, lecz jego licencja zezwala na jego użycie tylko do celów prywatnych.
// Uruchom program, sprawdź, czy proces potomny zacznie wyświetlać obrazek od razu, czy dopiero po zamknięciu potoku przez proces nadrzędny.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void run_child(int pipe_d[2]) {
        int buf[10000]; 

        close(pipe_d[1]);
        close(0);
        dup(pipe_d[0]); // teraz standardowym wyjsciem jest pipe_d[0], wyjscie pipe ustawiam na standardowe wejście procesu

        execlp("display","display", (char*) NULL); // tylko proces potomny to wykonuje
        // wyswietla obraz przesłany przez pipe
}

void run_parent(int file , int pipe_d[2]) {
        char buf[10000];        // ciag znakow ktory wpisuje do pliku
        int bufor_dlugosc=0;    // liczba odczytanych znakow
        close(pipe_d[0]);       // rodzic zamyka wyjście
        while(( bufor_dlugosc = read( file, buf, 10000 )) > 0 ) {
            write( pipe_d[1], buf, bufor_dlugosc ); // pipe_d[1] -> wejście
        }

        close(pipe_d[1]); // zamykam aby nie wisiał w powietrzu
}

int main(int argc, char* argv[]) {
        int file;
        int pipe_d[2];
        int child_pid = -1;

        if(argc != 2) {
                fprintf(stderr, "Niepoprawna liczba argumentow wywolania programu.", argv[0]);
                exit(-1);
        }

        file = open(argv[1], O_RDONLY); //plik który podaje (tylko czytanie (flaga))

        if(file <0) {
                fprintf( stderr, "Nie udalo sie otworzyc pliku zrodlowego", argv[1]);
                exit(-2);
        }

        if(pipe(pipe_d) == -1) {
                fprintf(stderr, "Blad przy tworzeniu potoku.");
                exit(-2);
        }

        child_pid = fork(); // proces potomny
        if(child_pid < 0) {
                fprintf( stderr, "Blad przy tworzeniu procesu potomnego.");
                exit(-2);
        } 
        else if(child_pid == 0) { // jesli 0 to utworzylem proces potomny
                run_child(pipe_d);
        }
        else { // proces pierwotny
                run_parent(file, pipe_d);
        }
        //fclose(file);

        return 0;
}
