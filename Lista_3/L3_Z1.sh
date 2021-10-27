# Zapoznaj się z programem ps (man ps). Wypróbuj dwa formaty wyświetlania rozszerzonych informacji: -f i -l. 
# Przeczytaj podręcznik polecenia ps aby zrozumieć wyświetlane parametry. Naucz się wybierać zestaw procesów do wyświetlania argumentami opcjonalnymi -u, -t, i -p.
# Ile Twoich procesów istniało w systemie w chwili przykładowego wywołania ps?

# Ile procesów sshd istniało w systemie (serwerze) w chwili wykonywania ćwiczenia (sprawdź polecenie pgrep)?

# ps -f - wyświetla aktwne procesy użytkownika w pełnym formacie.

# UID          PID    PPID  C STIME TTY          TIME CMD
# remigiu+   12700   12693  0 16:45 pts/1    00:00:00 bash
# remigiu+   15574   12700  0 17:41 pts/1    00:00:00 ps -f

# ps -l - wyświetla aktywne procesy użytkownika w długim formacie BSD.

# F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
# 0 S  1000   12700   12693  0  80   0 -  3329 do_wai pts/1    00:00:00 bash
# 4 R  1000   15612   12700  0  80   0 -  3508 -      pts/1    00:00:00 ps

# ps -u = wyświetla uruchomione procesy danego użytkownika

# Użytkownicy mogą również użyć ps polecenia w połączeniu z grep poleceniem (patrz polecenia pgrepi pkill), 
# aby znaleźć informacje o pojedynczym procesie, takie jak jego identyfikator:

# $ # Próba znalezienia PID `firefox-bin`, który wynosi 2701 
# $ ps -A | grep firefox-bin
#  2701 ? 22:16:04 firefox-bin

# Istniało 58 procesów sshd w systemie (serwerze) w chwili wykonania ćwiczenia (pgrep sshd)
