// Porównaj swoje rozwiązanie z tym przedstawionym w programie dotprod_mutex.c i arrayloops.c. 
// Wyjaśnij na czym polegają różnice w budowie tych dwóch programów. 
// Który z nich jest bardziej efektywny pod względem prędkości? Który z nich jest mniej zasobożerny (pamięć)?

// ODP
// Szybszy jest dotprod_mutex.c
// Mniej zasobożerny jest arrayloops.c

/*
remigiusz@remy:~/Pulpit/Programy_Visual_Studio/Lista_9$ gcc dotprod_mutex.c -pthread
remigiusz@remy:~/Pulpit/Programy_Visual_Studio/Lista_9$ ./a.out

Thread 0 did 0 to 1000000:  mysum=1000000.000000 global sum=1000000.000000
Thread 3 did 3000000 to 4000000:  mysum=1000000.000000 global sum=2000000.000000
Thread 1 did 1000000 to 2000000:  mysum=1000000.000000 global sum=3000000.000000
Thread 2 did 2000000 to 3000000:  mysum=1000000.000000 global sum=4000000.000000
Sum =  4000000.000000 
It took 10113.216 microseconds to run.


remigiusz@remy:~/Pulpit/Programy_Visual_Studio/Lista_9$ gcc arrayloops.c -pthread
remigiusz@remy:~/Pulpit/Programy_Visual_Studio/Lista_9$ ./a.out

Thread 1 doing iterations 2500000 to 4999999
Thread 0 doing iterations 0 to 2499999
Thread 2 doing iterations 5000000 to 7499999
Thread 3 doing iterations 7500000 to 9999999
Done. Sum= 5.000000e+13 
It took 29738.081 microseconds to run.
Check Sum= 5.000000e+13
*/




// Program dotprod_mutex.c jest oparty na strukturze
// Program arrayloops.c    jest oparty na tablicy