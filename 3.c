#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int main(void)
{
	sigset_t set;
	int ret;
	int sig_num;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	
	ret = sigprocmask(SIG_BLOCK, &set, NULL);
	if (ret < 0)
	{
		perror("Signal handler not set!\n");
		exit(-1);
	}

	while(1)
	{
		sigwait(&set, &sig_num);
		printf("Sig number %d\n", sig_num);
	}

	exit(0);
	
	return 0;
}