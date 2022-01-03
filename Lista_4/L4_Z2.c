// Dodaj w stworzonym programie przechwytywanie sygnału/ów, i wykorzystując sygnały: SIGALRM, SIGTERM, SIGUSR1, SIGUSR2 wypróbuj następujące reakcje na sygnał: 
// (a) wyświetlenie komunikatu i zakończenie pracy programu. (SIGALRM)
// (b) wyświetlenie komunikatu i powrót do wykonywania programu. (TERM)
// (c) wstrzymywanie odebrania sygnału (np. na 1000 iteracji w pętli), i następnie wznowienie odebrania sygnału. (USR1)
// (d) całkowite ignorowanie sygnału. (USR2) 

// 100ms = 100*10^(-3)s = 0,1s
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

/* wait 0 sec and 10^5 nanosec */
struct timespec ts = {0, 1000000L};

void sigalrm_przechwyc(int syg)
{
    printf("Sygnał alrm, program kończy działanie\n");
    exit(1);
}

void sigusr2_przechwyc(int syg)
{
    signal(SIGUSR2,SIG_IGN);
}

void sigusr1_przechwyc(int syg)
{
    for(int i=0;i<1000;i++) {}
    // wznowienie
    raise(syg);
    signal(SIGUSR1,SIG_DFL); // Sygnał jest obsługiwany przez domyślną akcję dla tego konkretnego sygnału.
}

void sigterm_przechwyc(int syg)
{
    printf("Sygnał term - i powrót do wykonywania programu....\n");
}

int main()
{
    signal(SIGALRM, sigalrm_przechwyc);
    signal(SIGTERM, sigterm_przechwyc);
    signal(SIGUSR1, sigusr1_przechwyc);
    signal(SIGUSR2, sigusr2_przechwyc);
    for (int i=0; ; )
    {
        i += 1;
        nanosleep (&ts, NULL);
        
    }

    return 0;
}

// kill -s SIGALRM pid_a.out