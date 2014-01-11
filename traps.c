#include <stdio.h>
#include <string.h>
int main()
{

  // size_t data type. because the strlen will return a size_t type data.However, size_t type is an 
  // unsigned long. -1 will be considered as 4294967295, which is greater than 5.
  int size_t_int = -1;
  if(size_t_int > strlen("Demon"))
    printf("%d is greater than %zu.\n", size_t_int, strlen("Demon"));        // will be printed out.
  else
    printf("%d is not greater than %zu.\n", size_t_int, strlen("Demon"));
  
  return 0;
}
