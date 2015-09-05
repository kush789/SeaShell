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

int seashell_get_command(char ** command)
{
	unsigned char ch;
	int pos, buffer_size, status;

	pos = 0;
	buffer_size = SEASHELL_BUFF_LENGTH;

	*command = (char *) malloc((buffer_size + 1) * sizeof(char));

	while(1)
	{
		ch = getchar();

		if ((int)ch == EOF || ch == '\n')
		{
			(*command)[pos] = '\0';
			status = 0;
			goto cleanup;
		}
		else
			(*command)[pos++] = ch;

		if (pos > buffer_size)
		{
			buffer_size += SEASHELL_BUFF_LENGTH;
			if (!realloc(*command, buffer_size + 1))
			{
				status = 1;
				goto cleanup;
			}
		}
	}

	cleanup:

	return status;
}
