// Tworzenie wątków
// Przejrzyj kod programu hello32.c. Zwróć uwagę, że tworzy on 32 wątki. Polecenie sleep() zostało wprowadzone, aby upewnić się, że wszystkie wątki będą istnieć w tym samym czasie. Dodatkowo, każdy wątek wykonuje prawdziwą pracę, aby zademonstrować jak zachowanie planisty systemu operacyjnego determinuje kolejność wykonywania wątków.
// Skompiluj i uruchom program (użyj flagi -lm). Zwróć uwagę na kolejność w której wyświetlane są wyjścia wątków. Czy zawsze jest taka sama? Jakie jest tego wyjaśnienie?


// remigiusz@remy:~/Pulpit/Programy_Visual_Studio/Lista_8/kod1$ ./a.out
// main(): Created 32 threads.
// 0: Hello World!
// 22: Hello World!
// 3: Hello World!
// 7: Hello World!
// 1: Hello World!
// 8: Hello World!
// 4: Hello World!
// 12: Hello World!
// 27: Hello World!
// 15: Hello World!
// 16: Hello World!
// 5: Hello World!

// Wątki dostają różną ilość zasobów obliczeniowych

// Jak widać, wątek 22 musiał dostać ich bardzo dużo, ponieważ zakończył swoje działanie na początku, 
// a powinien być jednym z ostatnich wywołanych (zakładając, że każdy dostaje tyle samo)