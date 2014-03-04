#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char str1[] = "hello";
  char str2[] = "hello";
  char *name[] = {
    "Liu", "Li" , "Du"
  };

  //  str1 = name[1];
  char *str   = name[1];         // name[i] is a pointer
  printf("str : %s \n", str);
  printf("The size of name[i] is %zu.\n", sizeof(name[1]));

  if(str1 == str2){
    printf("== operator will be the comparison of value \n");
  } else {
    printf("== operator will be the comparison of address \n");          // right
  }

  if(strcmp(str1,str2) == 0){
    printf("function strcmp is for the comparison of string value \n");   // right
  } else {
    printf("function strcmp is for the comparison of string address \n");
  }
  
  // compare char * with a char array. It's ok.
  if(strcmp(str,"Li") == 0){
    printf("strcmp can be used for the comparison between char * and char array.\n");
  } else {
    printf("strcmp can't be used for the comparison between char * and char array.\n");
  }

  // the format should be %d when you want to output an character instead of string.
  printf("Print out the decimal %d value of char %c.\n\n", str1[1],str1[1]);
  // printf("%s\n", str1[1]);  %s expects argument of type char* but argument have type of int.

//==============================================================================
//                     The length of char * and char array
//==============================================================================
  char *p = "hello";
  char q[] = "hello";         // The null terminator will be included as well.
  
  printf("The usage of function sizeof and strlen : \n");
  printf("%zu\n", sizeof(p)); // => 8. size of pointer to char -- 4 on x86, 8 on x86-64
  printf("%zu\n", sizeof(q)); // => 6. size of char array in memory -- 6 on both

  // size_t strlen(const char *s) and we don't get any warnings here:
  printf("%zu\n", strlen(p)); // => 5
  printf("%zu\n\n", strlen(q)); // => 5

//==============================================================================
//                     assign a value to char array
//==============================================================================
  // 1. initial a char array with a string
  char init_arr[4] ="name";
  printf("The value of char array init_arr is %s.\n", init_arr);

  char init_str1[4] = "book";
  char init_str2[4] = {'l','i','k' };

  printf("Two ways to initial a char array %s and %s.\n", 
         init_str1,init_str2);     // book & lik
  
  // 2. The assignment of char array : strcpy function or for loop. 
  char assign_arr1[4];
  char assign_arr2[4];
  strcpy(assign_arr1,init_str1);    // initial with other char array
  strcpy(assign_arr2,"face");       // initial with a string
  printf("assigned char array %s through strcpy function with other char array.\n", 
         assign_arr1);   // book
  printf("assigned char array %s through strcpy function with a string.\n", 
         assign_arr2);           // face

  char assign_arr3[4];
  long unsigned i;
  printf("The length of char array %zu.\n",sizeof(assign_arr3));
  for(i = 0; i< sizeof(assign_arr3);i++){
    assign_arr3[i] = 'm';           // assign a char to char array one by one. 
  }
  printf("assigned char array %s through for loop.\n\n",assign_arr3);      // mmmm

//==============================================================================
//                    declarate and define the array of char pointer 
//==============================================================================
  char *char_pointer_arr1[] = {
    "Liu", "Li" , "Du"
  };
  // 24. because the element is a pointer
  printf("The length of char * array %zu.\n",sizeof(char_pointer_arr1));   
  printf("Number of elements in char * array %zu.\n",
         sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]));   // 3
  
  for(i =0; i < sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]); i++) {
    printf("The %zust element of char_pointer_arr1 is %s.\n",i,char_pointer_arr1[i]);
  }
  printf("\n");

//==============================================================================
//                  assignment to char pointer
//==============================================================================  
  char * c = "hello";
  char c2 = 'a';
  char *c3 = &c2;
  printf("c is : %s\n",c);
  printf("c3 is :%c\n",*c3);
  printf("c[1] is :%c\n",*c);

//==============================================================================
//                  Convert int to string
//==============================================================================  
  int aInt = 368;
  char str4[15]="\0";
  sprintf(str4, "%d", aInt);
  printf("convert int aInt to string : %s\n",str4);

//==============================================================================
//                  Convert string to int
//==============================================================================  
  //  char * s2i = "\xff\xff\xff\xfe";
  char * s2i = "\x2D\x31\x32\x33\x34";
  int signed_i = atoi(s2i);
  printf("s2i is : %s\n", s2i);            // -1234
  printf("signed_i is : %d\n", signed_i);

  char * s2i2 = "\x31\x32\x33\x34";
  int signed_i2 = atoi(s2i);
  printf("s2i2 is : %s\n", s2i2);          // 1234
  printf("signed_i2 is : %d\n", signed_i2);

//==============================================================================
//                  compare signed char to unsigned char
//==============================================================================  
  signed char c4 = 0x31;
  printf("The length of signed char c4 is %zu\n",sizeof(c4));
  unsigned char c5 = 0x31;
  if(c4 == c5)
    printf("signed char c4(%x) is equal to unsigned char c5(%x)\n", c4,c5);
  else 
    printf("signed char c4(%x) is not equal to unsigned char c5(%x)\n", c4,c5);

  signed char c6 = 0xf3;
  unsigned char c7 = 0xf3;
  if(c6 == c7)
    printf("signed char c6(%x) is equal to unsigned char c7(%x)\n", c6,c7);
  else 
    printf("signed char c6(%x -> %d) is not equal to unsigned char c7(%x ->%d)\n", c6,c6,c7,c7);

//==============================================================================
//              extend char to int 
// unsigned char --> int : 0xff --> 0x000000ff
// signed char   --> int : oxff --> 0xffffffff
// check the bit value through gdb command
//==============================================================================

  unsigned char c8 = 0xFF;
  signed char c9 = 0xFF;
  printf("Decimal and Hex format of unsigned char c8 is %d, %x.\n",c8,c8);
  printf("Decimal and Hex format of signed char c9 is %d, %x.\n",c9,c9);
  
  int t1 = c8;
  int t2 = c9;
  printf("Decimal and Hex format of unsigned char t1 is %d, %x.\n",t1,t1);
  printf("Decimal and Hex format of signed char t2 is %d, %x.\n",t2,t2);

//==============================================================================
//                       The end
//==============================================================================  
  return 0;
}
