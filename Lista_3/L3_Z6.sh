# Sprawdź możliwość zawieszania procesu sygnałem SIGSTOP i wznawiania sygnałem SIGCONT. 
# Sprawdź, że sygnał SIGSTOP daje taki sam efekt jak naciśnięcie klawisza Ctrl+Z na terminalu. 
# Sprawdź, że sygnał SIGCONT daje taki sam efekt jak wykonanie polecenia fg lub bg (którego bardziej?).

remigiusz@remy:~$ ps -u
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
remigiu+    3306  0.0  0.0  13316  5052 pts/0    Ss   14:16   0:00 /usr/bin/bash
remigiu+    5830  0.0  0.0   2608  1580 pts/0    S+   14:45   0:00 sh L3_Z5.sh
remigiu+   13472  0.1  0.0  13316  4908 pts/1    Ss   15:07   0:00 bash
remigiu+   13572  0.0  0.0  10608   580 pts/0    S+   15:08   0:00 sleep 2
remigiu+   13573  0.0  0.0  14112  3352 pts/1    R+   15:08   0:00 ps -u
remigiusz@remy:~$ kill -s STOP 5830
remigiusz@remy:~$ kill -s CONT 5830
remigiusz@remy:~$ kill -s SIGKILL 5830
remigiusz@remy:~$ ps -u
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
remigiu+    3306  0.0  0.0  13316  5100 pts/0    Ss+  14:16   0:00 /usr/bin/bash
remigiu+   13472  0.0  0.0  13316  4928 pts/1    Ss   15:07   0:00 bash
remigiu+   13917  0.0  0.0  14112  3348 pts/1    R+   15:09   0:00 ps -u
remigiusz@remy:~$ jobs -l # w visualu
remigiusz@remy:~$ fg %1
remigiusz@remy:~$ bg %1 odpala z &