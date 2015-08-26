#include "program.h"

int main(int argc, char* argv[])
{
	ThreadData td[NUM_THREADS];

	createThreads(td);
	
	puts("Main thread created all child threads..");

	joinThreads(td);

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

void joinThreads(ThreadData* td)
{
	for(uint8 j = 0; j < NUM_THREADS; ++j)
		if(pthread_join(td[j].tid, NULL))
			errorHandle("Error joining thread");
}
