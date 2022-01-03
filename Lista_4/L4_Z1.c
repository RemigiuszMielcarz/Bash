// Napisz program wykonujący jakąś trywialną operację (np. ++i;) w nieskończonej pętli. 
// Skompiluj i uruchom program, a następnie programem top sprawdź, czy Twój program pokazuje się w czołówce programów wykorzystujących cykle obliczeniowe komputera. 
// Przed przejściem do dalszych prac zabij program klawiszem Ctrl-C. Dodaj w pętli opóźnienie (sleep(1);, a najlepiej nanosleep(); z opóźnieniem np. 100 milisekund) 
// i upewnij się, że po uruchomieniu tego programu nie pojawia się on już na szczycie listy top. 
// Domyślna częstotliwość odświeżania programu top jest mała, spróbuj ją zmienić korzystając z dostępnej pomocy programu. 
// Zapisz co należało dodać do wywołania programu. 

// 100ms = 100*10^(-3)s = 0,1s
#include <stdio.h>
#include <time.h>

/* wait 0 sec and 10^5 nanosec */

struct timespec ts = {0, 1000000L};

int main()
{
    for (int i=0; ; )
    {
        i += 1;
        nanosleep (&ts, NULL);
    }

    return 0;
}

// gcc -pedantic -Wall nazwaprogramu
// Wykorzystuje całe zasoby CPU gdy nie ma funkcji nanosleep
// Wykorzystuje 1,6% CPU gdy jest nanosleep

// By zwiększyć częstotliwość odświeżania programu top należało dodać: top -d 00.10

// top -u rmielcar