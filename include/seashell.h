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

/* Macros */

#define SEASHELL_BUFF_LENGTH 1024
#define SEASHELL_TOKEN_SIZE 64
#define SEASHELL_TOKEN_DELIM " \t\r\n\a"

/* Initializes shell */
int seashell_begin();

/* reads command from stdin */
int seashell_get_command(char ** command);

/* splits stdin input into command and args */
int seashell_understand_command(char *** arguments, char * command);

/* forks and executes command ising execvp */
void seashell_execute_command(char ** arguments);

void seashell_execute_nonbuiltin(char ** arguments);

/* Handles ctrl + c respectfully */
void seashell_kill();

/* builtin cd */
void seashell_builtin_cd(char ** arguments);

/* builtin cd */
void seashell_builtin_help(char ** arguments);

/* EXIT CODES :
*	
*	0. No problem woo hoo
*	1. Memory allocation problem
*
*
*/