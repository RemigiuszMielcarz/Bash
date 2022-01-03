// Program będzie teraz mapował pliki graficzne (JPEG lub PNG),
// stworzony zostanie proces potomny, który następnie uruchomi program (jedną z funkcji exec*) wyświetlający obrazek ze zmapowanego pliku z opcją aktualizacji,
// w razie potrzeby proces nadrzędny wymusi aktualizację wyświetlanego obrazu przez podproces (funkcja memcntl/MC_SYNC???).

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
  	struct stat fdstat;
  	char filename[100];
  	char* mem = NULL;
  	size_t size = 0;
	int prot = PROT_READ | PROT_WRITE;
	int fd[2]; 			

	system("touch buf");
	fd[0] = open("buf", O_RDWR);
    pid_t pid = fork();

    if(pid == 0) { // proces potomny
        execlp("display", "display", "buf", (char*) NULL);
    }
    else {
	    while(strncmp(filename, "exit", 4) != 0) {
      		    puts("Podaj nazwe pliku");
      		    scanf("%s", filename);
      		    fd[1] = open(filename, O_RDONLY);
      		    stat(filename, &fdstat);
      		    ftruncate(fd[0], size + fdstat.st_size);
    		    mem = mmap(NULL, size + fdstat.st_size, prot, MAP_SHARED, fd[0], 0);
      		    read(fd[1], mem + size, fdstat.st_size);
      		    close(fd[1]);
      		    size += fdstat.st_size;
    	    }
    }

  	munmap(mem, size);
  	close(fd[0]);
  	system("rm buf");
}
