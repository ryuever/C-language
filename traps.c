//=============================================== file = traps.c ================
//=  Traps in C language                                                        =
//===============================================================================
//=  Notes:                                                                     =
//=    1) To make it easier to read, I make the definition of structure         =
//=       just in front of a block where it is first referred to.               =
//=-----------------------------------------------------------------------------=
//= Example :                                                                   =
//=                                                                             =
//=-----------------------------------------------------------------------------=
//= Example output                                                              =
//=-----------------------------------------------------------------------------=
//=  Build: gcc -g traps.c                                                      =
//=-----------------------------------------------------------------------------=
//=  Author: Liu Youchao                                                        =
//=-----------------------------------------------------------------------------=
//=  History:                                                                   =
//===============================================================================
//----- Include files -----------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int foo(char **x){
  *x = malloc(4);
  memset(*x,'a',3);
  (*x)[3] = '\0';
  return 0;
}

int main()
{
//===============================================================================
// size_t data type. because the strlen will return a size_t type data.However, 
// size_t type is an unsigned long. -1 will be considered as 4294967295, which 
// is greater than 5.
//===============================================================================
  int size_t_int = -1;
  if(size_t_int > strlen("Demon"))
    printf("%d is greater than %zu.\n", size_t_int, strlen("Demon"));        
  else
    printf("%d is not greater than %zu.\n", size_t_int, strlen("Demon"));
//===============================================================================
// For a char array, '\0' indicate the end. so when you initialize strcpy[3] with
// 3 length string. The default '\0' of strcpy1[2] is overrided by '3'. So the  
// actual length of strcpy1 depend on the position of the first '\0' it encounter.
// Now it is 6. It could be any number.
//===============================================================================
  char strcpy1[3]="123";
  printf("The length of strcpy1 (before strcpy) : %zu.\n",strlen(strcpy1));
  printf("The length of strcpy1 (before strcpy) : %zu.\n",sizeof(strcpy1));
  strcpy(strcpy1, "hello world!");
  printf("strcpy1 is assigned with value of %s.\n", strcpy1);   // "hello world!"
  printf("The length of strcpy1 is : %zu.\n",strlen(strcpy1));
  printf("\n");
//===============================================================================
//                    Initialize with '0','\0',0
//===============================================================================
  char membuff[5]; 
  memset(membuff, '\0', 4);                        // initilize buffers to nulls
  printf("The initial value membuff is %s.\n", membuff);
  printf("membuff[0] is %x.\n", *membuff);

  memset(membuff, 0, 4);                        // initilize buffers to nulls
  printf("The initial value membuff is %s.\n", membuff);
  printf("membuff[0] is %x.\n", *membuff);

  memset(membuff, '0', 5);                        // char 0, overflow
  printf("The initial value membuff is %s.\n", membuff);
  printf("membuff[0] is %x.\n", membuff[6]);

  printf("\n");
//===============================================================================
//                              EOF trap
// $  gcc -g -fsigned-char traps.c      // stop at the third char oxff
// $  gcc -g -funsigned-char traps.c    // go into loop
//===============================================================================
  char c;
  FILE *fp = fopen("test.txt","r+");
  fputs("\x35\x38\xff\x32\x33",fp);
  fclose(fp);

  FILE *fp2 = fopen("test.txt","r");
  while ((c = fgetc(fp2)) != EOF){
    printf ("read c2 = '%c'\n", c);
  }

  fclose(fp);

//===============================================================================
// null pointer as argument
//===============================================================================
  char *mm;
  foo(&mm);
  printf("mm is %s\n",mm);
  return 0;

//===============================================================================
//                             The End
//===============================================================================
  return 0;
}
