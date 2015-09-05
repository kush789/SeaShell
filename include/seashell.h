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

#define SEASHELL_BUFF_LENGTH 10

int seashell_begin();

int seashell_get_command(char ** command);

int seashell_execute_command();

/* EXIT CODES :
*	
*	0. No problem woo hoo
*	1. Memory allocation problem
*
*
*/