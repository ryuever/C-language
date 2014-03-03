#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
//==============================================================================
//                  how to open and read a file
// int open(const char* path, int oflags, mode_t mode);
// ssize_t read(int fd, void *buf, size_t count);
//==============================================================================
  int filedesc = open("test.txt",O_RDWR);
  printf("%d",filedesc);
  if(filedesc < 0)
    return 1;
  
  if(write(filedesc, "This will be output to test.txt\nI am lily. nice to meet you!\n",61) != 61){
    write(2,"There was an error writing to test.txt\n",43);
    return 1;
  }

  // count(25) is greater than buf_size(23), return 25. but Result is unspecified.
  int filedesc2 = open("test.txt",O_RDWR);
  char buf[23];
  memset(buf,'\0',23);
  int nread = read(filedesc2,buf,25);       
  if(nread == 25){
    printf("buf is : %s",buf);
  }
  
  // count(20) is less than buf_size(30), return 20. Result is acceptable
  char buf1[30];
  memset(buf1,'\0',30);
  if(read(filedesc2,buf1,20) == 20){
    printf("buf1 is : %s",buf1); 
  }
  
  // smaller characters left in file. so it just return the number char is really read.
  char buf2[30];
  memset(buf2,'\0',30);
  int nread2 = read(filedesc2,buf2,40);
  printf("buf2 is : %s",buf2); 
  printf("nread2 is : %d\n",nread2);
  
  return 0;
  }
