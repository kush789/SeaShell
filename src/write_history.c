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
#include "unistd.h"
#include "../include/seashell.h"

seashell_history_node * seashell_write_history(char * command)
{
	seashell_history_node * temp = malloc(sizeof(seashell_history_node));

	temp->command = malloc((SEASHELL_BUFF_LENGTH + 1) * sizeof(char));
	temp->next = NULL;

	strcpy(temp->command, command);

	return temp;
}
