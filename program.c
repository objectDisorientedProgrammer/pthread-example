#include "program.h"

int main(int argc, char* argv[])
{
	ThreadData td[NUM_THREADS];
	char tMsg = "Hello from thread ";
	
	// createThreads(...)
	for(int i = 0; i < NUM_THREADS; ++i)
	{
		td[i].id = i+1;
		strcpy(td[i].message, tMsg);
		pthread_create(&td[i].tid, NULL, threadFunction, td);
	}

	puts("Main thread created all child threads..");

	// joinThreads(...);
	for(int j = 0; j < NUM_THREADS; ++j)
		pthread_join(td[i].tid, NULL);
	puts("Main thread joined all child threads. Now exiting");

	return 0;
}

void* threadFunction(void* arg)
{
	ThreadData* data = (ThreadData*) arg;
	
	printf("[%d] %s %d.\n", data->tid, data->message, data->id);

	pthread_exit(0);
}
