#include "program.h"

int main(int argc, char* argv[])
{
	ThreadData td[NUM_THREADS];
	char* tMsg = "Hello from thread ";
	
	// createThreads(...)
	for(uint8 i = 0; i < NUM_THREADS; ++i)
	{
		td[i].id = i+1;
/*DBG*/	printf("td[%d].id = %d\n", i, td[i].id);
		strcpy(td[i].message, tMsg);
		if(pthread_create(&td[i].tid, NULL, threadFunction, td))
			errorHandle("Error creating thread");
	}

	puts("Main thread created all child threads..");

	// joinThreads(...);
	for(uint8 j = 0; j < NUM_THREADS; ++j)
		if(pthread_join(td[j].tid, NULL))
			errorHandle("Error joining thread");

	puts("Main thread joined all child threads. Now exiting");

	return 0;
}

// TODO use <stdarg.h> to make this function take variable # of args
void errorHandle(const char* msg)
{
	fprintf(stderr, msg);
	exit(-1);
}

void* threadFunction(void* arg)
{
	ThreadData* data = (ThreadData*) arg;
	
	printf("[%ld] %s%d.\n", data->tid, data->message, data->id);

	pthread_exit(0);
}
