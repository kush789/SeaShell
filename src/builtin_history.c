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
#include "../include/seashell.h"

void seashell_builtin_history()
{
	seashell_history_node * temp = HEAD;
	int count = 0;

	while (temp != NULL)
	{
		printf("[%d] %s\n", count + 1, temp->command);
		count += 1;
		temp = temp->next;
	}
}
