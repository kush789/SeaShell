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

seashell_history_node * seashell_create_history(char * command,
												seashell_history_node ** HEAD)
{
	if (*HEAD == NULL)
	{
		*HEAD = seashell_write_history(command);
		(*HEAD)->next = NULL;
	}
	else
	{
		seashell_history_node * temp = seashell_write_history(command);
		temp->next = *HEAD;
		*HEAD = temp;
	}

	return *HEAD;
}
