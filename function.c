//=============================================== file = function.c =============
//=  A tutorial program of compound types (struct, union) in C language         =
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
//=  Build: gcc -g function.c                                                   =
//=-----------------------------------------------------------------------------=
//=  Author: Liu Youchao                                                        =
//=-----------------------------------------------------------------------------=
//=  History:                                                                   =
//===============================================================================
//----- Include files -----------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct student{
  char grade; /* char is 1 byte long */
  int  age;   /* int is 4 bytes long */
}tt = {1,378};

int main(){
//===============================================================================
//                      functions in stddef.h
//===============================================================================
//===============================================================================
//                          functions in stdio.h  
//===============================================================================



//===============================================================================
//                          functions in string.h  
//===============================================================================
  printf("==================================================================\n");
  printf("char * strcpy ( char * dest, const char * src ).\n");
  printf("==================================================================\n");
  char strcpy1[3]="12";
  printf("The length of strcpy1 (before strcpy) : %zu.\n",strlen(strcpy1));
  printf("The length of strcpy1 (before strcpy) : %zu.\n",sizeof(strcpy1));
  strcpy(strcpy1, "hello world!");
  printf("strcpy1 is assigned with value : %s.\n", strcpy1);   // "hello world!"
  printf("The length of strcpy1 (after strcpy)  : %zu.\n",strlen(strcpy1));
  printf("\n");

  printf("==================================================================\n");
  printf("char * strcat ( char * dest, const char * src ).\n");
  printf("==================================================================\n");
  char strcat1[80];
  strcpy (strcat1,"hello");
  printf("dest before strcat : %s.\n",strcat1);
  strcat (strcat1," world!");
  printf("dest after strcat  : %s.\n",strcat1);
  printf("\n");  

  printf("==================================================================\n");
  printf("char * strncat ( char * dest, const char * srce, size_t num ).\n");
  printf("==================================================================\n");
  char strncat1[4];
  char strncat2[20];
  strcpy (strncat1,"To be ");
  strcpy (strncat2,"or not to be");
  printf("strncat1 is : %s.\n",strncat1);
  printf("strncat2 is : %s.\n",strncat2);
  printf("The length of strncat1 (before strcpy) : %zu.\n",strlen(strncat1));
  strncat (strncat1, strncat2, 5);
  printf("The length of strncat1 (after strcpy)  : %zu.\n",strlen(strncat1));
  printf("Appending 6 chars to strncat1 : %s.\n", strncat1);  // "To be or not"
  printf("\n");

  printf("==================================================================\n");
  printf("void * memset ( void * ptr, int value, size_t num ).\n");
  printf("==================================================================\n");
  char memset1[] = "almost every programmer!";
  printf("memset1 before memset : %s.\n", memset1);  // "almost every programmer!"
  memset(memset1,'-',6);
  printf("memset1 after memset : %s.\n", memset1);   // "------ every programmer!"

  char membuff[5]; 
  memset(membuff, '\0', 5);                        // initilize buffers to nulls
  printf("The initial value membuff is %s.\n", membuff);
  printf("membuff[0] is %x.\n", *membuff);
  printf("\n");
  
  printf("==================================================================\n");
  printf("void * memcpy ( void * dest, const void * src, size_t num ).\n");
  printf("==================================================================\n");
  char memcpy1[20] = "hello";
  memcpy(memcpy1, "-", 3);
  printf("memcpy1    : %s\n", memcpy1);   // %s will terminal when encounter '\0' 
  printf("memcpy1[1] : %x\n", memcpy1[1]);     // '\0'  
  printf("memcpy1[2] : %c\n", memcpy1[2]);     // 'm'   arbitary character
  printf("memcpy1[3] : %c\n", memcpy1[3]);     // 'l'  
  printf("memcpy1[4] : %c\n", memcpy1[4]);     // 'o'
  printf("\n");
  
  printf("==================================================================\n");
  printf("void bcopy(const void *src, void *dest, size_t n);\n");
  printf("==================================================================\n");
  char bcopy1[10];
  char bcopy2[] = "almost every programmer!";
  bcopy(bcopy2,bcopy1,6);
  printf("bcopy : %s.\n",bcopy1);
  printf("\n"); 

  printf("==================================================================\n");
  printf("int strcmp(const char *s1, const char *s2);\n");
  printf("int strncmp(const char *s1, const char *s2, size_t n);\n");
  printf("==================================================================\n");

  /* char *s1 = "\012"; */
  /* char *s2 = "\n\012"; */

  char *s1 = "\012";
  char *s2 = "\n\012";

  if(strcmp(s1,s2) < 0){
    printf("s1(%s) is less than s2(%s).\n",s1,s2);
  }else if(strcmp(s1,s2) > 0){
    printf("s1(%s) is greater than s2(%s).\n",s1,s2);
  }else {
    printf("s1(%s) is equal to s2(%s).\n",s1,s2);
  }
  
  if(strncmp(s1,s2,1) < 0){
    printf("s1(%s) is less than s2(%s).\n",s1,s2);
  }else if(strncmp(s1,s2,1) > 0){
    printf("s1(%s) is greater than s2(%s).\n",s1,s2);
  }else {
    printf("s1(%s) is equal to s2(%s).\n",s1,s2);
  }

  printf("\n");



  /* char *line2 = malloc(30); */
  /* char *test = malloc(23); */
  /* memset(test,'\0',13); */
  /* char *t = "hello"; */
  /* printf("The size of line2 : %zu\n",strlen(test));   */


  char *test3;
  strcpy(test3,"hello");
  printf("test3 is %s.\n",test3);
//===============================================================================
//                            The end
//===============================================================================
  return 0;
}
