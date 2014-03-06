#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct student{
  char grade; /* char is 1 byte long */
  int  age;   /* int is 4 bytes long */
}tt = {1,378};

int main(){
  printf("==================================================================\n");
  printf("sizeof unary-expression.\n");
  printf("==================================================================\n");
  printf("The length of a char and int is %zu and %zu,respectively.\n", 
         sizeof(char), sizeof (int));
  printf("The length of unsigned int is %zu.\n", sizeof(unsigned int));
  printf("The length of size_t is %zu. \n", sizeof(size_t));
  printf("The length of ssize_t is %zu. \n", sizeof(ssize_t));
  printf("\n");

  printf("==================================================================\n");
  printf("The length of array and string pointer.\n");
  printf("==================================================================\n");
  int sizeof_int[10];
  char char_arr[3];
  printf("The sizeof int array sizeof_int is %zu.\n", sizeof(sizeof_int));
  printf("The sizeof char array is %zu.\n", sizeof(char_arr));
  printf("The strlen of char array string : %zu.\n", strlen(char_arr));
  printf("\n");

  char strcpy1[3]="12";
  strcpy(strcpy1, "hello world!");
  printf("// when char array overflow : \n");
  printf("The original sizeof strcpy1 : %zu.\n",sizeof(strcpy1));
  printf("strcpy1 is assigned with value : %s.\n", strcpy1);   // "hello world!"
  printf("The length of strcpy1 (after strcpy)  : %zu.\n",strlen(strcpy1));
  printf("\n");

  char string[32] = "hello, world";
  printf("The sizeof char array sizeof_int : %zu.\n", sizeof(string));
  printf("The strlen of char array string : %zu.\n", strlen(string));

  char *ptr = string;
  printf("The sizeof pointer ptr : %zu.\n", sizeof(ptr));         // pointer length is 8
  printf("The strlen of pointer ptr : %zu.\n", strlen(ptr));

  // applied to the name of a static array.The result will be the bytes of the 
  // whole array
  char *char_pointer_arr1[] = {
    "Liu", "Li" , "Du"
  };
  printf("The sizeof of char * array %zu.\n",
         sizeof(char_pointer_arr1));    // 24. because the element is a pointer
  printf("\n");
  
  // be used to calculate the number of elements in array.
  printf("Number of elements in char * array %zu.\n",
         sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]));   // 3
  printf("\n");

  printf("==================================================================\n");
  printf("sizeof struct or union  -- pay attention to structure padding\n");
  printf("==================================================================\n");
  printf("The length of struct student is %zu\n", sizeof(struct student));      // 8

  struct MixedData
  {
    char Data1;
    short Data2;
    int Data3;
    char Data4;
  };
  printf("The length of struct student is %zu.\n", sizeof(struct MixedData));    // 12 
  printf("\n");

  printf("==================================================================\n");
  printf("offsetof(type, member).\n");
  printf("==================================================================\n");
  printf("The offset of(struct student, age) is %zu.\n", 
         offsetof(struct student, age));  // 4,padding is 3; 
  printf("offsetof(struct MixedData, Data2) is %zu.\n", 
         offsetof(struct MixedData, Data2));    // 2, padding for Data1 is 1
  printf("offsetof(struct MixedData, Data4) is %zu.\n", 
         offsetof(struct MixedData, Data4));    // 8
  printf("\n");

}
