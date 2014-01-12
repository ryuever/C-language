#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct student{
  char grade; /* char is 1 byte long */
  int  age;   /* int is 4 bytes long */
};

int main(){

  // funtion sizeof 
  int sizeof_int[10];
  char char_arr[3];
  printf("The length of a character is %zu, and the length of a interger is %zu\n", sizeof(char), sizeof (int));
  printf("The length of unsigned int is %zu.\n", sizeof(unsigned int));
  printf("The length of size_t is %zu. \n", sizeof(size_t));
  printf("The length of ssize_t is %zu. \n", sizeof(ssize_t));
  printf("The length of array sizeof_int is %zu.\n", sizeof(sizeof_int));
  printf("The length of char array is %zu.\n", sizeof(char_arr));
  printf("The length of struct student is %zu\n", sizeof (struct student));
  // applied to the name of a static array.The result will be the bytes of the whole array
  char *char_pointer_arr1[] = {
    "Liu", "Li" , "Du"
  };
  printf("The length of char * array %zu.\n",sizeof(char_pointer_arr1));   // 24. because the element is a pointer
  // be used to calculate the number of elements in array.
  printf("Number of elements in char * array %zu.\n",sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]));   // 3
  printf("\n");

  // sizeof struct or union  -- pay attention to structure padding
  printf("The length of struct student is %zu.\n", sizeof(struct student));               // 8 
  printf("The offsetof(struct student, age) is %zu.\n", offsetof(struct student, age));   // 4,padding is 3; 
  
  struct MixedData
  {
    char Data1;
    short Data2;
    int Data3;
    char Data4;
  };
  printf("The length of struct student is %zu.\n", sizeof(struct MixedData));                // 12 
  printf("The offsetof(struct student, age) is %zu.\n", offsetof(struct MixedData, Data2));  // 2, padding for Data1 is 1
  printf("The offsetof(struct student, age) is %zu.\n", offsetof(struct MixedData, Data4));  // 8
  printf("\n");
  /******************* function in stdio.h **********************/


  /******************* function in string.h **********************/
  // function strcat
  char strcat1[80];
  strcpy (strcat1,"these ");
  strcat (strcat1,"strings ");
  strcat (strcat1,"are ");
  strcat (strcat1,"concatenated.");
  printf("strcat1 is \"%s\"\n", strcat1);         // "these strings are concatenated."
  printf("\n");

  // function strncat 
  char strncat1[20];
  char strncat2[20];
  strcpy (strncat1,"To be ");
  strcpy (strncat2,"or not to be");
  strncat (strncat1, strncat2, 6);
  printf("strncat1 is \"%s\"\n", strncat1);       // "To be or not"
  printf("\n");

  // function strcpy
  char strcpy1[20];
  strcpy(strcpy1, "hello world!");
  printf("strcpy1 is \"%s\"\n", strcpy1);         // "hello world!"
  printf("\n");

  // function memset
  char memset1[] = "almost every programmer should know memset!";
  memset(memset1,'-',6);
  printf("memset1 is \"%s\"\n", memset1);        // "------ every programmer should know memset!"

  char memset2[20] = "hello";
  memset(memset2, '-', 3);
  printf("memset2 is \"%s\"\n", memset2);        // "---lo"

  char membuff[5]; 
  memset(membuff, 0, 5);                        // init both buffers to nulls

  // function memcpy
  char memcpy1[20] = "hello";
  memset(memcpy1, '-', 3);
  printf("memcpy1 is \"%s\"\n", memcpy1);       // "---lo" 
  printf("\n");

  /******************* function in string.h **********************/  
  // offsetof(type, member)
  printf("offsetof(struct student,age) is %zu.\n", offsetof(struct student,age));
  printf("\n");

  /************************* The end ******************************/
  return 0;
}
