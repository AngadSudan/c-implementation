#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define utilFile ".auditlog"
#define BUF_SIZE 1024

int getLineCount();
void readAuditFile();
void writeAuditFile(char* content);

int main(int argc, char* argv[]){
    if(argc<2){
        printf("Error: Missing Argument");
        exit(-1);
    }

    if(strcmp(argv[1],"--read")==0){
        readAuditFile();
    }else{
        writeAuditFile(argv[2]);
    }
    return 0;
}

int getLineCount(){
    int fd;
    ssize_t numRead;
    char buf[BUF_SIZE];

    fd = open(utilFile,O_RDONLY);
    if(fd==-1){
        printf("Error: failed to open file");
        exit(-1);
    }

    char ch;
    int lines = 1;
     while(read(fd, &ch, 1) > 0){
        if (ch == '\n')
            lines++;
    }

    close(fd);
    return lines;
}

void readAuditFile(){
    int fd;
    ssize_t numRead;
    char buf[BUF_SIZE];

    fd = open(utilFile,O_RDONLY);
    if(fd==-1){
        printf("Error: failed to open file");
        exit(-1);
    }

    while((numRead = read(fd,buf,BUF_SIZE))>0){
        buf[numRead] = '\0';
        printf("%s", buf);
    }

    close(fd);
    return;
}
void writeAuditFile(char* content){
    int fd,openFlags;
    mode_t filePermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    openFlags = O_CREAT | O_WRONLY | O_APPEND;
    fd = open(utilFile,openFlags, filePermissions);
    if (fd == -1) {
        printf("Error: failed to open file");
        exit(-1);
    }
    int size = strlen(content) + 10;
    char buffer[size];
    int lineNo = getLineCount();
    snprintf(buffer, sizeof(buffer), "%d. %s\n", lineNo, content);

    if (write(fd, buffer, strlen(buffer)) == -1) {
        printf("Error: failed to write file");
        exit(-1);
    }

    close(fd);
}