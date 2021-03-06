#include <stdio.h>
#include <string.h>

const char *byte_to_binary(int x){
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1){
      strcat(b, ((x & z) == z) ? "1" : "0");      // append to char array b.
    }
    return b;
}

int main(){      
  printf("==================================================================\n");
  printf("The usage of flag options : \n");
  printf("==================================================================\n");
  int flag_num1 = 30, flag_num2 = -25;
  printf("flag_num1 : %-5d, flag_num2 : %-5d\n", flag_num1,flag_num2);
  printf("flag_num1 : %-5d, flag_num2 : %+5d\n", flag_num1,flag_num2);
  printf("flag_num1 : % 5d, flag_num2 : % 5d\n", flag_num1,flag_num2);
  printf("flag_num1 : %05d, flag_num2 : %05d\n", flag_num1,flag_num2);
  printf("flag_num1 : %-+5d, flag_num2 : %-+5d\n", flag_num1,flag_num2);
  printf("flag_num1 : %0+5d, flag_num2 : %0+5d\n", flag_num1,flag_num2);
  printf("flag_num1 : %#x,  flag_num2 : %#o\n", flag_num1,flag_num2);
  printf("\n");

  printf("==================================================================\n");
  printf("The usage of width options : \n");
  printf("==================================================================\n");
  int wid_num = 2, wid_width = 4, wid_num2 = 123456;
  char *wid_str = "hello world";
  
  printf("wid_num  : %*d\n",wid_width, wid_num);
  printf("wid_num2 : %*d\n",wid_width, wid_num2);    // not truncated.
  printf("wid_str  : %*s\n", wid_width,wid_str);     // not truncated.

  printf("wid_num  : %2$*1$d\n",wid_width,wid_num);
  
  printf("==================================================================\n");
  printf("The usage of precision option\n");
  printf("==================================================================\n");
  
  float fl = 4.23;
  int fl_int = 243445;
  printf("int wid_num     : %.4d\n",wid_num);
  printf("int fl_int      : %.4d\n",fl_int);        // not truncated
  printf("float number fl : %.4f\n", fl);
  printf("string wid_str  : %.4s\n",wid_str);       // will be truncated
  
  printf("string wid_str  : %1$.*2$s\n",wid_str,wid_num);       // will be truncated
  printf("\n");

  printf("==================================================================\n");
  printf("The usage of specifier\n");
  printf("==================================================================\n");
  printf("%d %x %o\n", 10, 10, 10);  
  // %s : printf statement halt when encounter null terminator
  char printf_string[5]={'s','a','\0','c','h'};
  printf("printf_string is \"%s\"\n", printf_string);     // "sa"
  
  char *p = printf_string;
  int n;
  for(n = 0; n < 5; ++n) {
    printf("%c", *p ? *p : ' ');                // "sa ch", if you hit a null, print a space.
    ++p;
  }
  printf("\n");
  
  // print in binary format
  printf("The binary format of %d is %s\n", 5, byte_to_binary(5));
  printf("\n");

  unsigned long long a = 422342423424;
  printf("length of llu type    : %zu\n", sizeof(a));
  printf("unsignend long long a : %llu\n",a);

  long long b = 422342423424;
  printf("length of lld type    : %zu\n", sizeof(b));
  printf("unsignend long long b : %lld\n",b);

  long c = 422342423424;
  printf("length of long type   : %zu\n", sizeof(c));
  printf("long c                : %ld\n",c);
  printf("\n");

  // p for pointer address  
  float ptr[4] = { 1.0, 2.0, 3.0, 4.0 };
  printf("%p %p %p %p\n", &ptr[0], &ptr[1], &ptr[2], &ptr[3]);

  printf("\n");

//==============================================================================
// printf, fprintf, sprintf, snprintf, vprintf, vfprintf, vsprintf, vsnprintf - 
// formatted output conversion
//==============================================================================
  printf("==================================================================\n");
  printf("The usage of sprintf\n");
  printf("==================================================================\n");
  int sp_int = 14,rdchar;
  char str[20];
  rdchar = sprintf(str, "hex of sp_int : %#x", sp_int);
  printf("The read number of characters : %d\n",rdchar);
  printf("%s\n",str);
  if(rdchar > 19)
    printf("string is truncated to buffer str\n");
  else
    printf("string is read successfully\n");
  printf("hex of sp_int : %#x\n", 691212);

  return 0;
}
