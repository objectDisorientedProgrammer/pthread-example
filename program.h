#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MSG_SIZE 20
#define NUM_THREADS 4

typedef struct
{
	uint8 id;
	pthread_t tid;
	char message[MSG_SIZE];
} ThreadData;

void threadFunction(void* data);

#endif
