#include <stdio.h>

int main(){
  printf("\n");
  int i,j;
  for(i=0;i<5;i++){
    j++;
    if(j>2){
      printf("\n--------go into if statement -----------\n");
      printf("The value of j(in if stat) is : %d.\n",j);
      printf("--------go out from if statement -------\n\n");
      break;
    }
    // 一旦执行上面的break, 下面这句话就不再执行了
    printf("The value of j(in for loop) is : %d.\n",j);
  }
  printf("--------outside of for loop ----------------\n"); 
  printf("The value of j(outside of for loop) is : %d.\n\n",j);
  
  // 下面是验证当多层嵌套的时候，break只会跳出最近那层的loop
  // 执行过if语句的输出以及break以后，你会发现接下来的输出都是从while来的
  i = 0,j=0;
  while(i < 5){
    for(;i<3;i++){
      j++;
      if(j>1){
        printf("The value of j(in if stat) is : %d.\n",j);
        break;
      }
      printf("The value of j(in for loop) is : %d.\n",j);
    }
    printf("The value of j(in while loop) is : %d.\n",j);
    i++;
  }

  return 0;
}

