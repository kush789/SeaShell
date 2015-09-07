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
#include "../include/seashell.h"

int seashell_understand_command(char *** arguments, char * command)
{
	char * token;
	int pos, status, buffer_size;

	pos = 0;
	buffer_size = SEASHELL_TOKEN_SIZE;
	*arguments = (char **) malloc((buffer_size + 1) * sizeof(char *));

	if (!arguments)
	{
		status = 1;
		goto cleanup;
	}

	/* _/\_ thank god strtok exists _/\_ */

	token = strtok(command, SEASHELL_TOKEN_DELIM);

	while (token != NULL)
	{
		(*arguments)[pos++] = token;

		if (pos > buffer_size)
		{
			buffer_size += SEASHELL_TOKEN_SIZE;
			if (!realloc(*arguments, (buffer_size + 1) * sizeof(char *)))
			{
				status = 1;
				goto cleanup;
			}
		}

		token = strtok(NULL, SEASHELL_TOKEN_DELIM);
	}

	(*arguments)[pos] = NULL;
	status = 0;

	cleanup:

	return status;
}
