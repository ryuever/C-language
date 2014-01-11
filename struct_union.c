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
  printf("The size of struct people_hdr is %lu.\n", sizeof(struct people_hdr));
  printf("PLEN is %lu", PLEN);
  return 0;
}
