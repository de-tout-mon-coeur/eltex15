#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
	pid_t pid;

	if (argc < 2)
	{
		printf("Usage: %s PID\n", argv[0]);
		return -1;
	}

	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);

	return 0;
}