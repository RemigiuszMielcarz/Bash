// Program, który:
// wykona mapowanie obszaru pamięci do pliku na dysku (funkcja mmap), w taki sposób, aby zapisy do pamięci były widoczne w pliku,
// będzie wykonywał w pętli nieskończonej następujące operacje na plikach tekstowych:
// odpyta użytkownika o nazwę pliku,
// obliczy długość pliku i zmieni odpowiednio wielkość obszaru pamięci wspólnej i zmapowanego pliku (funkcje stat, mmap, ftruncate),
// wczyta podany plik do zmapowanego obszaru pamięci.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
  	struct stat fdstat; // sprawdza ile pamieci zarezerwowac dla "buf"
  	char filename[100];
  	char* mem = NULL;
  	size_t size = 0;
	int prot = PROT_READ | PROT_WRITE;
	int fd[2]; 			// 0 - bufor (wyjscie), 1 - content (wejscie)

	system("touch buf");
	fd[0] = open("buf", O_RDWR);

	while(strncmp(filename, "exit", 4) != 0) { 
      		puts("Podaj nazwe pliku");
      		scanf("%s", filename);
      		fd[1] = open(filename, O_RDONLY);
      		stat(filename, &fdstat); 				 // aktualizacja rozmiaru pliku, który mamy sprawdzać
      		ftruncate(fd[0], size + fdstat.st_size); // ... , ile do tej pory, ile przybyło
    		mem = mmap(NULL, size + fdstat.st_size, prot, MAP_SHARED, fd[0], 0);
      		read(fd[1], mem + size, fdstat.st_size); // czytamy z wejścia
      		close(fd[1]);
      		size += fdstat.st_size; 				 // powiekszamy pamiec
    	}


  	munmap(mem, size);
  	close(fd[0]);
  	system("rm buf");
}
