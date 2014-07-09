//=============================================== file = operator.c =============
//=  A tutorial program of C operator                                           =
//===============================================================================
//=  Notes:                                                                     =
//=    1) To make it easier to refer to, I have listed typedef statements       =
//=       in front of the block it is first referred to.                        =
//=-----------------------------------------------------------------------------=
//= Example :                                                                   =
//=                                                                             =
//=-----------------------------------------------------------------------------=
//= Example output                                                              =
//=-----------------------------------------------------------------------------=
//=  Build: gcc -g operator.c                                                   =
//=-----------------------------------------------------------------------------=
//=  Author: Liu Youchao                                                        =
//=-----------------------------------------------------------------------------=
//=  History:                                                                   =
//===============================================================================
//----- Include files -----------------------------------------------------------
#include <stdio.h>

int main(){
  int x = 1, y=2;
//==============================================================================
//                           binary operators  &,|
// Bitwise complement : the tilde, ~, flips every bit. if you have a 1, it's 
//                      a 0, and if you have a 0, it's a 1. 
// compared with Bor, '~' just need one operand for this operator.
//==============================================================================
  int bcmt;
  bcmt = ~x;
  printf("      ~x(%d) = %d.\n", x,bcmt);

  // Bitwise or, which need two operands.
  int bor;
  bor = x | y;
  printf("x(%d) | y(%d) = %d.\n",x,y,bor);
  
  // Bitwise and, which need two operands.
  int band;
  band = x & y;
  printf("x(%d) & y(%d) = %d.\n", x,y,band);

  int commaOpe,commaOpe2;
  commaOpe = ~0,0;
  commaOpe2 = (~0,0);
  printf("comma operator (~0,0) return value : ox%x and ox%x\n", commaOpe,commaOpe2);

  int set = 4, signo = 7;
  set = 1 << (signo - 1);
  printf("left bit shift : ox%x\n", set);

//==============================================================================
//                          compound assignment 'op='
// where op can be any one of the ten operator symbols '*', '/', '%', '+', '-', 
// '<<', '>>', '&', '^' or '|'. 
//==============================================================================
  int cmpd1 = 5;
  cmpd1 |= 3;
  printf("      cmpd1 = %d.\n",cmpd1);

  printf("==================================================================\n");
  printf("Arithmetic operator \n");
  printf("==================================================================\n");
  int mod1 = 3;
  int mod2 = 7;
  printf("mod value (%d %% %d) : %d\n",mod2,mod1,mod2 % mod1);
  printf("\n");
  
  return 0;
}
