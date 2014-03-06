#include <stdio.h>

int main(){
  int x = 4;
  switch(x){
    int y = 5;  // Declaration will be executed, but initialization is igored,
    printf("This will never print");   // will not be executed.
    // printf("y is %d",y);
  case 1 :
    y = x + 1;
    printf("x = %d, use a varialbe y declared in switch statement.\n", y);
    break;
  case 4 :
    printf("y : %d", y);     // The value will be 0;
    y = y + 4;               // y is 4; 
    printf("x = %d, use a varialbe y declared in switch statement.\n",y);
    break;
  case 5:
    // int z;               // in case statement,declaration is also forbidened
    // int z = 6;           // in case statement, initialization is not allowed
    break;
  }
  return 0;
}
