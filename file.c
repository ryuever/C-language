#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

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
  int nread2;

  // re-read file if errno is EINTR
  while((nread2 = read(filedesc2,buf2,40)) < 0){
    if(errno == EINTR){
      printf("restart the read of file");
    }
    return (-1);
  }
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
// $  gcc -g -fsigned-char file.c      // stop at the third char oxff
// $  gcc -g -funsigned-char file.c    // go into loop
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
// fgetc,  fgets,  getc,  getchar,  gets, ungetc - input of characters and strings
//===============================================================================
  FILE * in_fp = fopen("test.txt","r");
  
  int in_c;
  in_c = fgetc(in_fp);
  printf("in_c is %d\n",in_c);

  char in_str[5];
  fgets(in_str,5,in_fp);              // read at most 4 chars from stream
  printf("in_str is %s\n",in_str);

  in_c = getc(in_fp);
  printf("in_c through getc function : %d\n",in_c);

  printf("please enter a character : ");
  in_c = getchar();
  printf("in_c from stdin : %d\n",in_c);

  // gets(in_str) is deprecated
  /* gets(in_str); */
  /* printf("in_str from stdin : %s\n",in_str); */

  fclose(in_fp);
  printf("\n");

//===============================================================================
//               getline, getdelim - delimited string input
//===============================================================================
  FILE *getline_fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  getline_fp = fopen("test.txt", "r");
  if (getline_fp == NULL)
    exit(EXIT_FAILURE);
  
  while ((read = getline(&line, &len, getline_fp)) != -1) {
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);
  }
  
  free(line);
  fclose(getline_fp);

  char * line2 = malloc(5);
  FILE *getline_fp2;
  size_t len2 = 4;
  ssize_t read2;
  
  getline_fp2 = fopen("test.txt", "r");
  if (getline_fp2 == NULL)
    exit(EXIT_FAILURE);
  
  while ((read2 = getline(&line2, &len2, getline_fp2)) != -1) {
    printf("Retrieved line2 of length %zu :\n", read2);
    printf("%s", line2);
  }
  
  // check whether file end is reached.
  if(feof(getline_fp2)){
    printf("Reach the file end.\n");
  }else{
    printf("Errno is %d.\n", errno);
  }
  
  free(line2);
  printf("\n");

//===============================================================================
// readline - get a line from terminal
// run with $ gcc -g file.c -lreadline   or it will signal error 
// "undefined reference to `readline'"
//===============================================================================
  char *line_stin ;
  line_stin= readline("Enter a line : ");
  printf("The read line is %s",line_stin);

  free(line_stin);

  char* input, shell_prompt[100];
 
  // Configure readline to auto-complete paths when the tab key is hit.
  rl_bind_key('\t', rl_complete);
  
  for(;;) {
    // Create prompt string from user name and current working directory.
    snprintf(shell_prompt, sizeof(shell_prompt), "%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));
    
    // Display prompt and read input (n.b. input must be freed after use)...
    input = readline(shell_prompt);
    
    // Check for EOF.
    if (!input)
      break;
    
    // Add input to history.
    add_history(input);
    
    // Do stuff...
    
    // Free input.
    free(input);
  }
//===============================================================================
// fputc, fputs, putc, putchar, puts - output of characters and strings
//===============================================================================
  FILE *out_file = fopen("out_file.txt","w");
  fputc(0x34,out_file);
  
  fputs("hello world",out_file);
  
  int out_i;
  for(out_i=0;out_i<10;out_i++){
    putc(65+out_i,out_file);
  }

  printf("Output a char through function putchar : ");
  putchar('\x63');
  putchar(0x0a);

  puts("function puts(), automatically, appending a newline character.");
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
    fsetpos(pos_file2,&pos2);  // due to this step, the three times pos_c2 is the same 
  }

  fclose(pos_file2);
  printf("\n");

//===============================================================================
// perror - print a system error message
//===============================================================================
  FILE * errpf;
  errpf=fopen ("unexist.ent","rb");
  if (errpf==NULL){
    printf("errno is %d\n",errno);
    perror ("The following error occurred");
  }
  else
    fclose (errpf);

  printf("\n");

//===============================================================================
// malloc, free, calloc, realloc - allocate and free dynamic memory  
//===============================================================================
  int * buffer1, * buffer2, * buffer3;
  /* buffer1 = (int*) malloc (100*sizeof(int)); */
  /* buffer2 = (int*) calloc (100,sizeof(int)); */
  /* buffer3 = (int*) realloc (buffer2,500*sizeof(int)); */
  buffer1 = malloc (100*sizeof(int));
  buffer2 = calloc (100,sizeof(int));
  buffer3 = realloc (buffer2,500*sizeof(int));
  
  // In gdb compare buffer1 to buffer5, buffer1 still point to the original position.
  // However buffer5 is 0x00 pointing to nothing.
  char *buffer4;
  char *buffer5 = NULL;
  free (buffer1);
  free (buffer3);

//===============================================================================
//                             The End
//===============================================================================
  return 0;
}
