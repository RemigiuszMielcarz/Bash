// Zmienne warunkowe
// Przejrzyj, skompiluj i uruchom program condvar.c. Obserwuj wyjścia trzech wątków.
// Teraz przejrzyj, skompiluj i uruchom program bug1.c. Obserwuj wyjścia pięciu wątków. Co się dzieje? Czy potrafisz wyjaśnić dlaczego? Jak naprawić problem?
// Program bug4.c to kolejny przykład tego, co może pójść źle przy użyciu zmiennych warunkowych. 
// Przejrzyj go, skompiluj (jeśli używasz gcc, dołącz flagę -lm) i uruchom. Zaobserwuj wyjście i spróbuj naprawić program.

/*
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&threads[2], &attr, watch_count, (void *)2);
  pthread_create(&threads[3], &attr, inc_count, (void *)3);
  pthread_create(&threads[4], &attr, inc_count, (void *)4);
  pthread_create(&threads[5], &attr, inc_count, (void *)5);
  pthread_create(&threads[0], &attr, inc_count, (void *)0);
  pthread_create(&threads[1], &attr, inc_count, (void *)1);
*/

// Tylko jeden wątek może odbierać sygnał na raz




// W bug4.c
// Sygnał jest wysyłany zanim drugi wątek rozpoczął oczekiwanie na ten sygnał, więc nie ma szans na odebranie tego sygnału.