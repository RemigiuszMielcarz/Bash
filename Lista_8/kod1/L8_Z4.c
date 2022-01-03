// Tworzenie wątków
// Przejrzyj kod programu hello32.c. Zwróć uwagę, że tworzy on 32 wątki. Polecenie sleep() zostało wprowadzone, aby upewnić się, że wszystkie wątki będą istnieć w tym samym czasie. Dodatkowo, każdy wątek wykonuje prawdziwą pracę, aby zademonstrować jak zachowanie planisty systemu operacyjnego determinuje kolejność wykonywania wątków.
// Skompiluj i uruchom program (użyj flagi -lm). Zwróć uwagę na kolejność w której wyświetlane są wyjścia wątków. Czy zawsze jest taka sama? Jakie jest tego wyjaśnienie?

// Błąd polega na braku            pthread_exit(NULL);       na końcu funkcji main. Po dodaniu tego wszystkie wątki pracują poprawnie