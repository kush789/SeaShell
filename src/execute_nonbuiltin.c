/*=============================================================================
*
*					This file is part of SeaShell.
*
*	SeaShell is free software; you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation; either version 2 of the License, or
*	(at your option) any later version.
*
=============================================================================*/
/******************************************************************************
*
*	Copyright (C) 2015 Kushagra Singh | kushagra14056 @ iiitd.ac.in
*
******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "../include/seashell.h"

void seashell_execute_nonbuiltin(char ** arguments)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		int i = 1;

		while (arguments[i] != NULL)
		{
			if (strcmp("<", arguments[i]) == 0)
			{
				if (arguments[i + 1] == NULL)
				{
					printf("Seashell: No file given\n");
					arguments[i] = NULL;
					break;
				}

				int fd = open(arguments[i + 1], O_RDONLY, 0);
				if (fd < 0)
				{
					fprintf(stderr, "SeaShell: %s: ", arguments[0]);
					perror("");
					break;
				}
				else
				{
					dup2(fd, STDIN_FILENO);
    				close(fd);
    			}

    			arguments[i] = NULL;
			}
			else if (strcmp(">", arguments[i]) == 0)
			{
				if (arguments[i + 1] == NULL)
				{
					printf("Seashell: No file given\n");
					arguments[i] = NULL;
					break;
				}

				int fd = creat(arguments[i + 1], 0644);
				if (fd < 0)
				{
					fprintf(stderr, "SeaShell: %s: ", arguments[0]);
					perror("");
					break;
				}
				else
				{
					dup2(fd, STDOUT_FILENO);
					close(fd);
				}

    			arguments[i] = NULL;
			}
			
			i += 1;
		}

		if (execvp(arguments[0], arguments) == -1)
		{
			fprintf(stderr, "SeaShell: %s: ", arguments[0]);
			perror("");
		}
	}

	else if (pid < 0)
		perror("SeaShell: ");

	else
	{
		do 
			waitpid(pid, &status, WUNTRACED);
		while 
			(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

}
