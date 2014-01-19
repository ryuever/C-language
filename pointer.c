#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct people {
  int age;
  char name[20];
}people;

// typedef char * const (* (* const bar)[5])(int );
typedef int (* (* const p1)(int a, int b))(int c, int d);
typedef float * (* (*ptr)(int))(double **,char c);

//==============================================================================
// Function pointer as arguments, for any functions with the numbers and 
// types of arguments and return value are the same. At the meanwhile, they 
// implement a silimiar function. then we can pass a function pointer as 
// an argument to omit the dulplicate process.
//==============================================================================
typedef void ( * def_char_void)(char *);
void show(void (* fp)(char *), char * str)
{
  (*fp)(str); // apply chosen function to str
  printf("%s\n",str);
}

void ToUpper(char * str)
{
  while (*str)
    {
      *str = toupper(*str);
      str++;
    }
}

void Transpose(char * str)
{
  while (*str)
    {
      if (islower(*str))
        *str = toupper(*str);
      else if (isupper(*str))
        *str = tolower(*str);
      str++;
    }
}
//==============================================================================
// Function pointer array : the position of [] to indicate pointer array.
//==============================================================================
typedef int (* def_int_int)(int );

int func_01 (int a){
  printf("function func_01 : argument is %d \n",a);
  return 0;
}

void func_02 (int (* ptr)(int a),int b){
  printf("\nBeginning of func_02.\n");
  (*ptr)(b);
  printf("Ending of func_02.\n");
}

void func_03 ( int(* ptr[3])(int a),int b){
  printf("\nBeginning of func_03.\n");
  int i;
  for (i = 0; i<3 ; i++, ptr++){
    (*ptr)(b); 
  }
  printf("Ending of func_02.\n");
}

//==============================================================================
// Return a function pointer : 
// f4 : a pointer to function passing int and returning int.
// f3 : a function pointer passing a int and f4 returning a pointer to function
//      passing int and returning int.
// f5 : is the same with f4;
// f6 : compared to f3, the returning pointer is to a integer instead of a func.
//==============================================================================
typedef int (* f1(int, int (* f2)(int)))(int);  // not error, but not correct. 
typedef int(* (*f3)(int,int (* f4)(int)))(int);
typedef int (* (* f6)(int,int (* f5)(int)));

typedef int (*mmm) (int);  // return a pointer to a pointer to integer
typedef int ff(int (* (* f3(int,int (* f4)(int)))),int);  // 

def_int_int func_04(int a, def_int_int b){
  printf("\nBeginning of func_04, and int argument is %d.\n",a);
  printf("Ending of func_04.\n");
  return b;
}

int * func_05(int a, def_int_int b){
  printf("\nBeginning of func_04, and int argument is %d.\n",a);
  int m = 4;
  int * i = &m;
  b(m);
  printf("Ending of func_05.\n");
  return i;
}

int func_06(int * a, int b){
  printf("%d,%d",*a,b);
  return 0;
}
//==============================================================================
// Const function pointer : so far, it make no sense. Because the format that is 
//                   
// pointer to a const function : int (const * ptr)(int, int) is not allowed. 
// const function pointer : you just could initialize a value, any assignment 
//                          is not allowed.
//==============================================================================
typedef int (* const const_ptr)(int);
typedef int const ( * const_ptr2)(int,int);

int const_func_01(int a){
  printf("\nBeginning of const_func1, and int argument is %d.\n",a);
  printf("Ending of const_func1.\n");
  return 0;
}

int const_func_02(int a){
  printf("\nBeginning of const_func2, and int argument is %d.\n",a);
  printf("Ending of const_func2.\n");
  return 0;
}

int main(){
  printf("=====================================================================\n");
  printf("fundamental of C pointer.\n");
  printf("=====================================================================\n");

  int temp = 4;
  int * i = &temp;
  int * j = temp; 
  int * int_arr[3] = {&temp,&temp,&temp};

  printf("\n");

  printf("=====================================================================\n");
  printf("function pointer as arguments.\n");
  printf("=====================================================================\n");
  char str[]= "I am a boy.";
  def_char_void pfun;
  int choice;
  printf("please select a choice 1 for toupper or 2 for transpose :\n");
  scanf(" %d", &choice);
  
  switch (choice){
  case 1 : pfun = ToUpper; printf("function ToUpper will be invoked.\n");break;
  case 2 : pfun = Transpose; printf("function Transpose will be invoked.\n");break;
  }
  show(pfun, str);
  
  printf("\n");
  printf("=====================================================================\n");
  printf("function pointer array.\n");
  printf("=====================================================================\n");
  int a = 4;

  def_int_int func1 = func_01;
  func1(a);                               // invoke using a def_int_int variable
  func_02(func_01,a);

  def_int_int ptr_arr[3] = {func_01,func_01,func_01};
  // func_03 ({func_01,func_01,func_01},a);    // expected expression before ‘{’ token
  func_03(ptr_arr,a);
  
  printf("\n");

  printf("=====================================================================\n");
  printf("Return function pointer\n");
  printf("=====================================================================\n");
  mmm m = func_01;
  int b = 5;
  f3 func2 =  func_04;
  func2(b,func_01);
  f6 func3 = func_05;
  func3(b,func_01);

  printf("\n");

  printf("=====================================================================\n");
  printf("Return const function pointer\n");
  printf("=====================================================================\n");
  int c = 6;
  const_ptr const_func1 = const_func_01;
  const_func1(c);
  
  /* const_func1 = const_func_02;   // assignment of read-only variable 'const_func1' */
  
  printf("\n"); 

  return 0;
}
