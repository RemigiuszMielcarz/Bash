// Wstęp. Napisz prosty program wykorzystujący Pthreads, który:
// tworzy kilka wątków, z których każdy wypisuje na standardowym wyjściu napis zdefiniowany w następnym punkcie. Jako argument funkcja otrzymuje ID wątku,
// funkcja wyświetla na standardowym wyjściu napis 'Hello SCR. Written by thread ID' (gdzie ID jest identyfikatorem wątku), a następnie wywołuje pthread_exit aby zakończyć wątek.
// główny program wywołuje pthread_exit jako ostatnią czynność.
// Uwaga 1: Używając wybranego kompilatora, skompiluj swój program. Może to wymagać kilku prób, jeśli wystąpią błędy. Przykładowo:
// cc -o hello myhello.c -lpthread
// gcc -o hello myhello.c -pthread
// Uwaga 2: Uruchom swój program hello i zwróć uwagę na jego wyjście. Czy jest to tym, czego oczekiwałeś? Dla porównania, możesz skompilować i uruchomić dołączony przykładowy program hello.c.



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello SCR. Written by thread ID #%ld!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
