// Wykorzystaj program strace do znalezienia błędu w poniższym programie. Jaki sygnał zabił program? Co oznacza otrzymanie tego sygnału?

#include <stdio.h>
char * napis = "Witajcie moi mili ...";
int main(){
  unsigned int index =0;
  for (index; ; index++){
    printf("%c",napis[index]);
  }
  return 0;
}

// Program został zabity przez sygnał: SIGSEGV - naruszenie pamięci
// Powodem jest przekroczenie zakresu tablicy, następnie otrzymujemy sygnał
// Poprzez użycie flagi -T lub -r możemy zobaczyć które fragmenty kodu wykonują się najdłużej i są problematyczne. 