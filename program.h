#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdarg.h>
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

void errorHandle(const char* msg); // TODO use <stdarg.h> to make this function take variable # of args
void* threadFunction(void* arg);
void createThreads(ThreadData* td);
void joinThreads(ThreadData* td);

#endif
