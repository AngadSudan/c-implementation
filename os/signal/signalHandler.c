#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;
int SIGNALS_TO_KILL = 3;

void handle_sigint(int sig)
{
    signal_count++;
    if (signal_count == SIGNALS_TO_KILL)
    {
        signal_count = 0;
        exit(EXIT_FAILURE);
    }
}

int main()
{
    signal(SIGINT, handle_sigint);
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1)
    {
        sleep(1);
    }

    return 0;
}
