/*
	Example program to demonstrate pthreads.
    Copyright (C) 2015  Douglas Chidester

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

#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MSG_SIZE 				100u
#define DEFAULT_NUM_THREADS		4u
#define MIN_NUMBER_OF_THREADS	1u
#define MAX_NUMBER_OF_THREADS	100u

typedef char int8; // could use stdint instead

// define what data each thread will use
typedef struct
{
	int8 id;
	pthread_t tid;
	char message[MSG_SIZE];
} ThreadData;

// license for command line interfaces
char* license = "Copyright (C) 2015 Douglas Chidester. This program comes with\nABSOLUTELY NO WARRANTY;\
 This is free software, and you are welcome to\nredistribute it under certain conditions.\n";

// local functions
static void errorHandle(const char* msg);
static void* threadFunction(void* arg);
static void createThreads(ThreadData* td, int numberOfThreads);
static void joinThreads(ThreadData* td, int numberOfThreads);

static int promptForMoreThreads(void);
static void promptForNewMessage(char* msg);

#endif
