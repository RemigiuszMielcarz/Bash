// Za pomocą programu truss zlicz ilość wywołań funkcji printf, które wykonuje program ls, uruchomiony w Twoim katalogu.

// Aby sprawdzić, ile wywołań funkcji printf nastąpiło po użyciu komendy ls w moim katalogu domowym, 
// można użyć polecenia: truss -u libc:printf ls 2>&1 | grep printf | wc -l. Należy zwróconą wartość podzielić przez 2.