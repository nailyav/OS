#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
  struct stat s;
  char *str = "This is a nice day";
  char *address;
  int f = open("ex1.txt", O_RDWR);
  fstat(f, &s);
  int size = s.st_size;
  address = mmap(NULL, size, PROT_WRITE, MAP_SHARED, f, 0);
  ftruncate(f, strlen(str)*sizeof(char));
  strcpy(address, str);
  close(f);
  return 0;
}
