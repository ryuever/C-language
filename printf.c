#include <stdio.h>
#include <string.h>

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
      strcat(b, ((x & z) == z) ? "1" : "0");      // append to char array b.
    }
    return b;
}

int main(){
  
  printf("%d %x %o\n", 10, 10, 10);
  
  // %s : printf statement halt when encounter null terminator
  char printf_string[5]={'s','a','\0','c','h'};
  printf("printf_string is \"%s\"\n", printf_string);     // "sa"
  
  char *p = printf_string;
  int n;
  for(n = 0; n < 5; ++n)
    {
      printf("%c", *p ? *p : ' ');                // "sa ch", if you hit a null, print a space.
      // printf("%c", *p);                       
      ++p;
    }
  printf("\n");

  // print in binary format
  printf("The binary format of %d is %s\n", 5, byte_to_binary(5));

  return 0;
}
