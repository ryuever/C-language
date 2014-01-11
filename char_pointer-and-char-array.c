#include <stdio.h>
#include <string.h>
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

  /*********************** The length of char * and char array **********************/
  char *p = "hello";
  char q[] = "hello";         // The null terminator will be included as well.
  
  printf("The usage of function sizeof and strlen : \n");
  printf("%zu\n", sizeof(p)); // => 8. size of pointer to char -- 4 on x86, 8 on x86-64
  printf("%zu\n", sizeof(q)); // => 6. size of char array in memory -- 6 on both

  // size_t strlen(const char *s) and we don't get any warnings here:
  printf("%zu\n", strlen(p)); // => 5
  printf("%zu\n\n", strlen(q)); // => 5

  /***********************   assign a value to char array   *************************/
  // 1. initial a char array with a string
  char init_arr[4] ="name";
  printf("The value of char array init_arr is %s.\n", init_arr);

  char init_str1[4] = "book";
  char init_str2[4] = {'l','i','k' };

  printf("Two ways to initial a char array %s and %s.\n", init_str1,init_str2);     // book & lik
  
  // 2. The assignment of char array : strcpy function or for loop. 
  char assign_arr1[4];
  char assign_arr2[4];
  strcpy(assign_arr1,init_str1);    // initial with other char array
  strcpy(assign_arr2,"face");       // initial with a string
  printf("assigned char array %s through strcpy function with other char array.\n", assign_arr1);   // book
  printf("assigned char array %s through strcpy function with a string.\n", assign_arr2);           // face

  char assign_arr3[4];
  long unsigned i;
  printf("The length of char array %zu.\n",sizeof(assign_arr3));
  for(i = 0; i< sizeof(assign_arr3);i++){
    assign_arr3[i] = 'm';           // assign a char to char array one by one. 
  }
  printf("assigned char array %s through for loop.\n\n",assign_arr3);      // mmmm

  /*************   declarate and define the array of char pointer  *****************/
  char *char_pointer_arr1[] = {
    "Liu", "Li" , "Du"
  };
  printf("The length of char * array %zu.\n",sizeof(char_pointer_arr1));   // 24. because the element is a pointer
  printf("Number of elements in char * array %zu.\n",sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]));   // 3
  
  for(i =0; i < sizeof(char_pointer_arr1)/sizeof(char_pointer_arr1[1]); i++) {
    printf("The %zust element of char_pointer_arr1 is %s.\n",i,char_pointer_arr1[i]);
  }
  printf("\n");


  /************************* The end ******** **********************/
  return 0;
}
