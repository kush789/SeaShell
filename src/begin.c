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

int seashell_begin()
{
	int status;
	char * command;
	char ** arguments;
	ssize_t block_size;

	do {

		status = seashell_get_command(&command);
		printf("%s\n", command);

		if (status)
			goto cleanup;

	} while (!status);

	cleanup:

	free(command);	/* command is allocated memory in seashell_get_command() */

	return status;
}
