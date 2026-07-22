#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1024;

void removeComments(int fd);
void skipComment(int fd, char type);
void copyStringOrChar(int fd, char quote);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage format: ./remove_comments file.c");
        exit(-1);
    }

    int fd;
    int openFlag;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error reading file");
        exit(-1);
    }

    removeComments(fd);

    close(fd);
    return 0;
}

void removeComments(int fd)
{
    char ch, next;

    while (read(fd, &ch, 1) == 1)
    {
        if (ch == '"' || ch == '\'')
        {
            copyStringOrChar(fd, ch);
        }
        else if (ch == '/')
        {
            if (read(fd, &next, 1) != 1)
            {
                putchar('/');
                break;
            }

            if (next == '/')
                skipComment(fd, '/');
            else if (next == '*')
                skipComment(fd, '*');
            else
            {
                putchar('/');
                putchar(next);
            }
        }
        else
        {
            putchar(ch);
        }
    }
}

void skipComment(int fd, char type)
{
    char ch, prev = 0;

    if (type == '/')
    {
        while (read(fd, &ch, 1) == 1)
        {
            if (ch == '\n')
            {
                putchar('\n');
                break;
            }
        }
    }
    else
    {
        while (read(fd, &ch, 1) == 1)
        {
            if (prev == '*' && ch == '/')
                break;
            prev = ch;
        }
    }
}

void copyStringOrChar(int fd, char quote)
{
    char ch;

    putchar(quote);

    while (read(fd, &ch, 1) == 1)
    {
        putchar(ch);

        if (ch == '\\')
        {
            if (read(fd, &ch, 1) != 1)
                break;
            putchar(ch);
        }
        else if (ch == quote)
        {
            break;
        }
    }
}