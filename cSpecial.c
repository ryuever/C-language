#include <stdio.h>

int main(void){
  printf("==================================================================\n");
  printf("__attribute__ for defined types\n");
  printf("==================================================================\n");
  float a[4] = { 1.0, 2.0, 3.0, 4.0 };
  float b[4] __attribute__((aligned(0x1000))) = { 1.0, 2.0, 3.0, 4.0 };
  float c[4] __attribute__((aligned(0x10000))) = { 1.0, 2.0, 3.0, 4.0 };

  printf("no attribute assigned : %p %p %p %p\n", &a[0], &a[1], &a[2], &a[3]);
  printf("0x1000 alignment      : %p %p %p %p\n", &b[0], &b[1], &b[2], &b[3]);
  printf("0x10000 alignment     : %p %p %p %p\n", &c[0], &c[1], &c[2], &c[3]);
}
