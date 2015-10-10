/*
	Example program to demonstrate pthreads.
    Copyright (C) 2015  Doulas Chidester

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

#define MSG_SIZE 20
#define NUM_THREADS 4

typedef char uint8;

typedef struct
{
	uint8 id;
	pthread_t tid;
	char message[MSG_SIZE];
} ThreadData;

char* license = "Copyright (C) 2015 Douglas Chidester. This program comes with ABSOLUTELY NO WARRANTY; This is free software, and you are welcome to redistribute it under certain conditions.\n";

void errorHandle(const char* msg);
void* threadFunction(void* arg);
void createThreads(ThreadData* td, int numberOfThreads);
void joinThreads(ThreadData* td, int numberOfThreads);

int promptForInteractiveMode(void);

#endif
