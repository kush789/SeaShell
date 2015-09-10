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
#include "string.h"
#include "signal.h"
#include "../include/seashell.h"

int seashell_begin()
{
	int status, i;
	char * command;
	char ** arguments;

	signal(SIGINT, seashell_kill);

	HEAD = NULL;

	do {
		status = seashell_get_command(&command);	/* get command */

		if (status)
			goto cleanup;

		HEAD = seashell_create_history(command, &HEAD);

		status = seashell_understand_command(&arguments, command);

		if (status)
			goto cleanup;

		seashell_execute_command(arguments);
	} while (!status);

	cleanup:

	free(command);	/* command is allocated memory in seashell_get_command() */
	
	i = 0;			/* arguments is allocated mem in */
	while (1)		/* seashell_understand_command() */
	{
		if (arguments[i] == NULL)
			break;
		else
			free(arguments[i++]);
	}

	free(arguments);

	return status;
}
