#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
  size_t len;
  off_t offset;
  int fd;
  char* buf;
  size_t numRead,numWritten;

  if(argc<3){
    printf("usage %s file {r<length>|w<string>|s<offset>}\n",argv[0]);
    exit(-1);
  }

  int openFlags = S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH;
  fd = open(argv[1],O_RDWR | O_CREAT,openFlags);
  if(fd==-1){
    printf("Failed to open file\n");
    exit(-1);
  }

  for(int i=2;i<argc;i++){
    switch(argv[i][0]){
      case 'r':
        len = atoi(&argv[i][1]);
        buf = malloc(len);
        numRead = read(fd,buf,len);
        if(numRead == 0){
           printf("we have reached the EOF\n");
           free(buf);
           exit(-1);
         }else{
           printf("%s\n",buf);
          }
          free(buf);
        break;
      case 'w':
        numWritten = write(fd,&argv[i][1],strlen(&argv[i][1]));
        printf("number of bytes written %ld\n",numWritten);
        break;
      case 's':
        offset = atoi(&argv[i][1]);
        if(lseek(fd,offset,SEEK_SET) == -1){
          printf("Failed to seek the offset\n");
           exit(-1);
        };

        printf("seek completed\n");
        break;
      default:
        printf("character other than r w s are not allowed");
        exit(-1);
    }
  }
  exit(EXIT_SUCCESS); 
}
