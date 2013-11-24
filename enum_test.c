#include <stdio.h>

enum opcodetype {
  STOP,
  OPR, LDV, LDI, LDC, LDA, LDX, LDS, 
  STV, STX, STS,
  JMP, JMPF,  CALL,  RET,
  INCT, DECT, ENTER, LEAVE,
};

static char *optypename[] = {
  "*ERR*", "OPR", 
  "LDV", "LDI", "LDC", "LDA", "LDX", "LDS", 
  "STV", "STX", "STS",
  "JMP", "JMPF", "CALL", "RET",
  "INCT", "DECT", "ENTER", "LEAVE",
  0
};

int main(){
  printf("The value OPR is : %d \n", OPR);
  printf("The value OPR is : %s \n", optypename[OPR]);
  printf("The size of enum is %lu \n" , sizeof(optypename));   // unsigned int 160 
  printf("The size of enum is %lu \n" , sizeof(OPR));  // unsigned int 4

  // format '%d' expects argument of type 'int', but argument 2 has type of 'long unsigned int'
  // printf("The size of enum is %d \n" , sizeof(OPR)); 
  return 0;  
}
