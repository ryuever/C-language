#include <stdio.h>
#include <string.h>
int main(){
  char str1[] = "hello";
  char str2[] = "hello";
  
  char *name[] = {
    "Liu", "Li" , "Du"
  };

  //  str1 = name[1];
  char *str   = name[1];
  printf("str : %s \n", str);

  if(str1 == str2){
    printf("== operator for char array will be the comparison of value \n");
  } else {
    printf(" == operator for char array will be the comparison of address \n");
  }

  if(strcmp(str1,str2) == 0){
    printf("function strcmp is used for the comparison of string value \n");
  } else {
    printf("function strcmp is used for the comparison of string address \n");
  }
  
  // compare char * with a char array. It's ok.
  if(strcmp(str,"Li") == 0){
    printf("function strcmp can be used for the comparison between char * and char array \n");
  } else {
    printf("function strcmp can not be used for the comparison between char * and char array \n");
  }

  // the format should be %d when you want to output an character instead of string.
  printf("str1 : %s, str1[1] : %d \n", str1 , str1[1]);
  // printf("%s\n", str1[1]);  %s expects argument of type char* but argument have type of int.


  /* Below is for the test of char * and char array length */
  char *p = "hello";
  char q[] = "hello"; // no need to count this

  printf("%zu\n", sizeof(p)); // => size of pointer to char -- 4 on x86, 8 on x86-64
  printf("%zu\n", sizeof(q)); // => size of char array in memory -- 6 on both

  // size_t strlen(const char *s) and we don't get any warnings here:
  printf("%zu\n", strlen(p)); // => 5
  printf("%zu\n", strlen(q)); // => 5
  return 0;
}
