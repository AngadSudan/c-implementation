#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]){
  if(argc<3){
    printf("usage ./a.out file1 file2");
    exit(-1);
  }
  
  int inputFd,outputFd,openFlags;
  mode_t filePermissions;
  ssize_t numRead;
  char buf[BUF_SIZE];
	
  inputFd = open(argv[1],O_RDONLY);
  if(inputFd==-1){
    printf("Error: unable to open file %s\n",argv[1]);
    exit(-1);
  }

  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // rw-r--r-- 644
  outputFd = open(argv[2],openFlags,filePermissions);
  
  if(outputFd == -1){
    printf("Error: unable to open file %s\n",argv[2]);
    exit(-1);
  } 

  while((numRead = read(inputFd,buf,BUF_SIZE)) >0 ){
    if(write(outputFd,buf,numRead) != numRead){
    	printf("Error: Something went wrong with buffer translation");
	exit(-1);	
    }
  }

  close(inputFd);
  close(outputFd);

  return 0;
}
