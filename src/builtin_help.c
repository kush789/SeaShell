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

void seashell_builtin_help(char ** arguments)
{
	printf("\nHi, welcome to SeaShell, a simple shell written in C.\n");
	printf("Copyright (C) 2015 Kushagra Singh | kushagra14056 @ iiitd.ac.in\n\n");
	printf("The following commands are inbuilt :\n");
	printf("	* cd\n");
	printf("	* help\n\n");

}
