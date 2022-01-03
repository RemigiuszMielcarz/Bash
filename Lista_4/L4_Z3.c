//  Zapoznaj się z narzędziami umożliwiającymi odczyt pseudosystemu plików proc (man proc). 
//  W systemie Solaris pliki w tym systemie mają specyficzny format, i do ich odczytu i dekodowania treści służy odpowiedni zestaw programów. 
//  W systemie Linux pliki w /proc maja formaty tekstowe i można je odczytywać (a w konkretnych przypadkach również zapisywać) zwykłymi narzędziami do operacji 
//  na plikach tekstowych, jak: cat, grep, itp. Do wykonania ćwiczenia wybierz dowolny, działający program w systemie lub uruchom własny program.

//  Napisałem program wyświetlający "Hello world". Po uruchomieniu wyświetliłem listę pseudosystemu pików i przy pomocy polecenia cat wyświetliłem kod mojego programu
//  oraz plik limits, w którym znajdują się dane odnośnie limitów dla wykonywanego procesu:

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello world\n");
    sleep(1000);
    return 0;
}

// ps -lu rmielcar
// ls /proc/1584986
// cat /proc/1584986/cwd/L4_Z3.c
// cat /proc/1584986/limits

