#include <stdio.h>

#define PSIZE 128
#define	PLEN		(PSIZE - sizeof(struct people_hdr))	/* normal data len */

struct people_hdr{
  int age;
  char name[20];
  int id;
};

struct people{
  struct people_hdr phdr;
  char profile[120];
};


int main(){
  //  printf("The type of macro object PSIZE is %s", PSIZE);
  
  int i =5;
  int y = sizeof(i);

  printf("PLEN is %lu.\n", PLEN);       // the format of PLEN is unsigned long
  printf("The size of PSIZE is %d .\n", y);
  printf("The size of PSIZE is %lu .\n", sizeof(sizeof(i)));   // the return of sizeof() is long unsigned
  return 0;
}
