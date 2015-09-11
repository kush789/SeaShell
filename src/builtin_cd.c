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

void seashell_builtin_cd(char ** arguments)
{
	if (arguments[1] == NULL)
	{
		fprintf(stderr, "SeasSell: expected arguments");
		return;
	}

	if (chdir(arguments[1]) != 0)
	{
		fprintf(stderr, "SeaShell: %s: ", arguments[0]);
		perror("");
	}
}
