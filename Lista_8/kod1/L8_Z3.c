// Przekazywanie argumentów
// Przejrzyj kod programów hello_arg1.c oraz hello_arg2.c. Zauważ w jaki sposób do wątku przekazywany jest pojedynczy argument, oraz jak przekazać wiele argumentów przez strukturę. Skompiluj oraz uruchom oba programy i obserwuj wyjście.
// przejrzyj, skompiluj i uruchom program bug3.c. Co poszło nie tak? Jak to naprawić?


// w kodzie hello_arg1.c podajemy do funkcji create argumenty jako tablica
// w kodzie hello_arg2.c                                      jako struktura
// w bug3.c podajemy argumenty jako oryginał, a powinniśmy jako kopię. Rozwiązaniem jest utworzenie struktury albo tablicy.

//      KOMPILACJA
// gcc bug3.c -lm -pthread