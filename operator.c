#include <stdio.h>

int main(){
  
  int x = 1, y=2;
  
  /* binary operators  &,| */

  // Bitwise complement : the tilde, ~, flips every bit. if you have a 1, it's a 0, and if you have a 0, it's a 1. 
  // compared with Bor, we just need one operand for this operator.
  int Bct;
  Bct = ~x;
  printf("The Binary complement of %d is %d.\n", x,Bct);

  // Bitwise and, which need two operands.
  int Band;
  Band = x & y;
  printf("Bitwise and of %d and %d is %d.\n", x,y,Band);

  return 0;
}
