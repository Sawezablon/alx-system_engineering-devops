#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

/**
 * infinite_while - a function that runs forever
 * Return: 0
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Entry point
 * Return: 0
*/
int main(void)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid > 0)
			sleep(1);
		else
			exit(0);
		printf("Zombie process created, PID: %i\n", (int)child_pid);
	}
	infinite_while();

	return (0);
}
