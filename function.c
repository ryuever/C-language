#include <stdio.h>
#include <string.h>

int main(){

  /******************* function in stdio.h **********************/


  /******************* function in string.h **********************/
  
  // function strcat
  char strcat1[80];
  strcpy (strcat1,"these ");
  strcat (strcat1,"strings ");
  strcat (strcat1,"are ");
  strcat (strcat1,"concatenated.");
  printf("strcat1 is \"%s\"\n", strcat1);         // "these strings are concatenated."

  // function strncat 
  char strncat1[20];
  char strncat2[20];
  strcpy (strncat1,"To be ");
  strcpy (strncat2,"or not to be");
  strncat (strncat1, strncat2, 6);
  printf("strncat1 is \"%s\"\n", strncat1);       // "To be or not"

  // function strcpy
  char strcpy1[20];
  strcpy(strcpy1, "hello world!");
  printf("strcpy1 is \"%s\"\n", strcpy1);         // "hello world!"

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

  return 0;
}
