#!/bin/bash

# Napisz skrypt, który w pętli będzie coś robił (np. co sekundę wypisywał bieżącą godzinę).
# Sprawdź wysyłanie do procesu różnych sygnałów poleceniem kill (SIGINT, SIGQUIT, ale także SIGFPE, SIGILL).
# Następnie rozbuduj skrypt o przechwytywanie tych sygnałów (trap) i sprawdź, że to działa, to znaczy, że tak napisanego procesu nie da się zabić tymi sygnałami.
# Sprawdź możliwość uśmiercenia sygnałem SIGKILL procesu, który przechwytuje wszystkie 15 podstawowych sygnałów.
# Uwaga: trap jest wbudowanym poleceniem shella, i jego wywołanie trochę się różni pod różnymi shellami.
# Najłatwiej jest wykonać to ćwiczenie przy użyciu Bourne shella (/bin/sh), ponieważ bash wykonuje różne potajemne zabiegi z obsługą sygnałów.
# Jednak polecenie trap w Bourne shellu jest prymitywne - czytaj man sh.

# 2  - SIGINT
# 3  - SIGQUIT
# 9  - SIGKILL
# 8  - SIGFPE
# 15 - SIGTERM

while true; do
    trap 'echo "Polecenie trap wykonane"' 2 9 15 8
    echo "Jest godzina: $(date +%T)"
    sleep 2
done

# 9 SIGKILL unicestwiony
