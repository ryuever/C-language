#include <stdio.h>

struct my_float {
  float number;
}  __attribute__((aligned(0x1000)));

typedef struct people_hdr{
  int age;
  char name[19];
  int id;
} people_hdr;

typedef struct people_hdr_align{
  int age;
  char name[19];
  int id;
} __attribute__((aligned)) people_hdr_align;

typedef struct people_hdr_align2{
  int age;
  char name[19];
  int id;
} __attribute__((aligned(0x100))) people_hdr_align2;

typedef struct people_hdr2{
  int age;
} people_hdr2;

typedef struct people_hdr2_align{
  int age;
} __attribute__((aligned)) people_hdr2_align;

struct S { short f[3]; } __attribute__ ((aligned));

int main(void){
  printf("==================================================================\n");
  printf("__attribute__ for defined types\n");
  printf("==================================================================\n");
  float a[4] = { 1.0, 2.0, 3.0, 4.0 };
  float b[4] __attribute__((aligned(0x1000))) = { 1.0, 2.0, 3.0, 4.0 };
  float c[4] __attribute__((aligned(0x10000))) = { 1.0, 2.0, 3.0, 4.0 };

  printf("no attribute assigned  : %p %p %p %p\n", &a[0], &a[1], &a[2], &a[3]);
  printf("0x1000 alignment       : %p %p %p %p\n", &b[0], &b[1], &b[2], &b[3]);

  struct my_float str[4] = { {1.0}, {2.0}, {3.0}, {4.0} };
  printf("0x1000 align for strut : %p %p %p %p\n", &str[0], &str[1], &str[2], &str[3]);

  printf("0x10000 alignment      : %p %p %p %p\n", &c[0], &c[1], &c[2], &c[3]);
  printf("sizeof float array b   : %zu\n", sizeof(b));
  printf("\n");

  printf("==================================================================\n");
  printf("__attribute__ used in structure and the impact on structure size\n");
  printf("==================================================================\n");
  printf("sizeof struct S              : %zu\n", sizeof(struct S));
  printf("\n");

  printf("sizeof struct people_hdr     : %zu\n", sizeof(people_hdr));
  people_hdr phdr;
  printf("Address of struct people_hdr : %p\n", &phdr);
  printf("verify %zu\n", (unsigned long)&phdr % sizeof(people_hdr));

  printf("sizeof struct people_hdr_align     : %zu\n", sizeof(people_hdr_align));
  people_hdr_align phdr_align;
  printf("Address of struct people_hdr_align : %p\n", &phdr_align);
  printf("verify %zu\n", (unsigned long)&phdr_align % sizeof(people_hdr_align));
  printf("\n");

  printf("sizeof struct people_hdr_align2     : %zu\n", sizeof(people_hdr_align2));
  printf("\n");

  printf("sizeof struct people_hdr2     : %zu\n", sizeof(people_hdr2));
  people_hdr2 phdr2;
  printf("Address of struct people_hdr2 : %p\n", &phdr2);
  printf("verify %zu\n", (unsigned long)&phdr2 % sizeof(people_hdr2));

  printf("sizeof struct people_hdr2_align     : %zu\n", sizeof(people_hdr2_align));
  people_hdr2_align phdr2_align;
  printf("Address of struct people_hdr2_align : %p\n", &phdr2_align);
  printf("verify %zu\n", (unsigned long)&phdr2 % sizeof(people_hdr2_align));
  printf("\n");
}
