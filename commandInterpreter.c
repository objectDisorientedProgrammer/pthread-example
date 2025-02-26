/*
	Command line I/O handler.
    Copyright (C) 2015-2019  Douglas Chidester

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "commandInterpreter.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let the user change number of threads created if desired
int promptForMoreThreads(void)
{
    char response[MAX_MSG_SIZE];
    int numThrds;
    // prompt user
    printf("Would you like to change the number of threads created? (y/N) ");
    fgets(response, MAX_MSG_SIZE, stdin);

    switch(*response)
    {
        case 'y':
        case 'Y':
            // get new number of threads
            printf("Please enter the number of threads you would like (1-100): ");
            numThrds = atoi(fgets(response, MAX_MSG_SIZE, stdin));

            // make sure new number is within limits
            if(numThrds < MIN_NUMBER_OF_THREADS)
                numThrds = MIN_NUMBER_OF_THREADS;
            else if(numThrds > MAX_NUMBER_OF_THREADS)
                numThrds = MAX_NUMBER_OF_THREADS;
            break;
        default:
            numThrds = DEFAULT_NUMBER_OF_THREADS;
            break;
    }

    return numThrds;
}

// Let the user change the thread message if desired
void promptForNewMessage(char* msg, int length)
{
    printf("Would you like to change the thread message? (y/N) ");
    fgets(msg, MAX_MSG_SIZE, stdin);

    switch(*msg)
    {
        case 'y':
        case 'Y':
            // get new number of threads
            printf("Please enter a new message:\n    ");
            if(fgets(msg, MAX_MSG_SIZE, stdin) == NULL)
                errorHandle("No new message was entered.\n");

            // remove extra newline
            char* last = strrchr(msg, '\n');
            *last = '\0';
            break;
        default:
            // default return value
            strcpy(msg, "Hello from this thread.");
            break;
    }
}

void displayHelp(void)
{
    puts("\nUsage: runner [threadCount]");
}
