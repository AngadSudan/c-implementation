#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("In child process");
        printf("id of Parent proces: %d\n", getppid());
        printf("id of child process: %d\n", getpid());
    }
    else
    {
        printf("In parent process\n");
        printf("id of Parent proces: %d\n", getpid());
        printf("id of child process: %d\n", pid);
        sleep(5);
    }

    return 0;
}