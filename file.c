#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
//==============================================================================
//                  how to open and read a file
// int open(const char* path, int oflags, mode_t mode);
// ssize_t read(int fd, void *buf, size_t count);
//==============================================================================
  int filedesc = open("test.txt",O_RDWR);
  printf("file descriptor : %d\n",filedesc);
  if(filedesc < 0)                  // if return value is negative, exit.
    return 1;
  
  if(write(filedesc, "This will be output to test.txt\nI am lily. nice to meet you!\n",61) != 61){
    write(2,"There was an error writing to test.txt\n",39);   // file descriptor 2 is stand error
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

//==============================================================================
//                    EOF : End of FIle 
// EOF = -1. It doesn't exist in file. In other word, it don't occupy byte in 
// file.
//==============================================================================
  int filedesc4 = open("test2.txt",O_RDWR | O_CREAT);
  write(filedesc4, "",10);
  char str[20];
  
  int nread4 = read(filedesc4, str, 10);
  
  printf("Reading a empty file, it will return 0.\n");
  printf("nread4 is : %d\n",nread4);    // nread4 = 0.no char is read. 
  
  printf("EOF is %x.\n" ,EOF);  
//===============================================================================
// if file not existing. The pointer to file will be Null
//===============================================================================
  FILE * fp;
  int c;           // must be declared to integer to receive fgetc(fp)
  if((fp = fopen("test.txt","rb")) == NULL){
    printf("file can't be opened.\n");
  }

  if((c = fgetc(fp)) == EOF){
    perror("reach the end of file.\n");
  }
  fclose(fp);
//===============================================================================
//                              EOF trap
// $  gcc -g -fsigned-char traps.c      // stop at the third char oxff
// $  gcc -g -funsigned-char traps.c    // go into loop
//===============================================================================
  FILE *fp2 = fopen("test.txt","r+");
  fputs("\x35\x38\xff\x32\x33",fp);
  fclose(fp2);

  char c3;
  FILE *fp3 = fopen("test.txt","r");
  while ((c3 = fgetc(fp3)) != EOF){
    printf ("read c2 = '%c'\n", c);
  }
  printf("\n");
  fclose(fp);

//===============================================================================
//                         int feof ( FILE * stream ); 
// Check end-of-file indicator : Checks whether the end-of-File indicator 
// associated with stream is set, returning a value different from zero if it is.
//===============================================================================
  FILE * pFile;
  int n = 0;
  pFile = fopen("myfile.txt","a+");
  if (pFile==NULL) 
    perror ("Error opening file");
  else {
    while (fgetc(pFile) != EOF) {
      ++n;
    }
    if (feof(pFile)) {
      puts ("End-of-File reached.");
      printf ("Total number of bytes read: %d\n", n);
    }
    else puts ("End-of-File was not reached.");
    fclose (pFile);
  }
  printf("\n");
  
//===============================================================================
//       fgetpos, fseek, fsetpos, ftell, rewind - reposition a stream
//===============================================================================
  FILE *pos_file = fopen("pos_file.txt","w");
  fputs("hello world.",pos_file);
  
  fseek(pos_file,2,SEEK_SET);
  fputs("2",pos_file);

  fseek(pos_file,0L,SEEK_SET);
  fputs("1",pos_file);

  //  rewind(pos_file);

  long pos1 = ftell(pos_file);
  printf("long pos is %zu\n",pos1);
  
  fclose(pos_file);

  FILE *pos_file2 = fopen("pos_file.txt","r");
  fpos_t pos2;
  fgetpos(pos_file2,&pos2);
  
  int i;
  char pos_c2;
  for(i=0;i<3;i++){
    pos_c2 = fgetc(pos_file2);
    printf("The %dst times  pos_c : %c\n",i,pos_c2);
    fsetpos(pos_file,&pos2);  // due to this step, the three times pos_c2 is the same 
  }

  fclose(pos_file);
  printf("\n");
//===============================================================================
//                             The End
//===============================================================================
  return 0;
}
