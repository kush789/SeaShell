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
#include "../include/seashell.h"

void seashell_execute_nonbuiltin(char ** arguments)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
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
