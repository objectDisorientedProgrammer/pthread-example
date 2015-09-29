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

#include "program.h"

int main(int argc, char* argv[])
{
	ThreadData td[NUM_THREADS];

	puts(license); // show GPL at start of program output

	createThreads(td);
	
	puts("Main thread created all child threads..");

	joinThreads(td);

	puts("Main thread joined all child threads. Now exiting.\n");

	return 0;
}

// Print an error message to stderr
void errorHandle(const char* msg)
{
	fprintf(stderr, msg);
	exit(-1);
}

// Each thread executes this function
void* threadFunction(void* arg)
{
	ThreadData* data = (ThreadData*) arg;
	
	printf("[%ld] %s%d.\n", data->tid, data->message, data->id);

	pthread_exit(0);
}

// Create all threads and catch errors
void createThreads(ThreadData* td)
{
	char* tMsg = "Hello from thread ";
	
	for(uint8 i = 0; i < NUM_THREADS; ++i)
	{
		td[i].id = i+1;
		strcpy(td[i].message, tMsg);
		if(pthread_create(&td[i].tid, NULL, threadFunction, &td[i]))
			errorHandle("Error creating thread");
	}
}

// Collect finished threads and catch errors
void joinThreads(ThreadData* td)
{
	for(uint8 j = 0; j < NUM_THREADS; ++j)
		if(pthread_join(td[j].tid, NULL))
			errorHandle("Error joining thread");
}
