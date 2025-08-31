#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sig_handler(int sig_num, siginfo_t *info, void *args) 
{
    int* param = (int* ) args;
    printf("SIGUSR1 - %d %d %d\n", sig_num, *param, info->si_signo);
}

int main() 
{
    struct sigaction handler;
    sigset_t set;
    int ret;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    handler.sa_sigaction = sig_handler;
    handler.sa_mask = set;

    ret = sigaction(SIGUSR1, &handler, NULL);
    if (ret < 0)
    {
    	perror("Signal handler not set!\n");
    	exit(-1);
    }

    while(1)
    {
    	sleep(1);
    }

    exit(0);

    return 0;
}
