/*************************************************************************
    > File Name: wait.c
    > Author: Actually
    > Created Time: 2017年08月18日 星期五 15时59分59秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    char *msg = NULL;
    int k;
    int exit_code;

    printf("Study how to get exit code\n");
    pid = fork();
    switch(pid)
    {
	case 0:
	    msg = "Child process is running\n";
	    k = 5;
	    exit_code = 37;
	    break;
	case -1:
	    perror("Process creation failed\n");
	    exit(1);
	default:
	    exit_code = 0;
	    break;
    }

    if (pid != 0)
    {
	int stat_val;
	pid_t child_pid;

	child_pid = wait(&stat_val);
	printf("Child process has exited, pid = %d\n", child_pid);
	if (WIFEXITED(stat_val))
	    printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
	else
	    printf("Child exited abnormally\n");
    }
    else
    {
	while (k-- > 0)
	{
	    puts(msg);
	    sleep(1);
	}
    }

    exit(exit_code);
}
