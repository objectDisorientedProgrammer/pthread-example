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
	puts(license); // show GPL at start of program output
	
	int threads = promptForMoreThreads();
	ThreadData td[threads];
	createThreads(td, threads);
	
	puts("Main thread created all child threads..");

	joinThreads(td, threads);

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
	
	printf("[%ld, %d] %s\n", data->tid, data->id, data->message);

	pthread_exit(0);
}

// Create all threads and catch errors
void createThreads(ThreadData* td, int numberOfThreads)
{
	char tMsg[MSG_SIZE];

	promptForNewMessage(tMsg);
	
	for(uint8 i = 0; i < numberOfThreads; ++i)
	{
		td[i].id = i+1;
		strcpy(td[i].message, tMsg);
		if(pthread_create(&td[i].tid, NULL, threadFunction, &td[i]))
			errorHandle("Error creating thread");
	}
}

// Collect finished threads and catch errors
void joinThreads(ThreadData* td, int numberOfThreads)
{
	for(uint8 j = 0; j < numberOfThreads; ++j)
		if(pthread_join(td[j].tid, NULL))
			errorHandle("Error joining thread");
}

// Let the user change number of threads created if desired
int promptForMoreThreads(void)
{
	char response = '\0';
	int numThrds = 0;
	printf("Would you like to change the number of threads created? (y/N) ");
	scanf("%c", &response);
	
	switch(response)
	{
		case 'y':
		case 'Y':
			// get new number of threads
			printf("Please enter the number of threads you would like: ");
			scanf("%d", &numThrds);
			return numThrds;
	}
	fflush(stdin);
	// default return value
	return NUM_THREADS;
}

// Let the user change the thread message if desired
void promptForNewMessage(char* msg)
{
	printf("Would you like to change the thread message? (y/N) ");
	scanf("%c", msg);
	
	switch(*msg)
	{
		case 'y':
		case 'Y':
			// get new number of threads
			printf("Please enter a new message:\n    ");
			fflush(stdin);
			scanf("%s", msg);
			//if(fgets(msg, MSG_SIZE, stdin) == NULL)
			//	errorHandle("No new message was entered.\n");
			return;
	}
	fflush(stdin);
	strcpy(msg, "Hello from this thread.");
}
