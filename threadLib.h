/*
	Thread API.
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

#ifndef PTHREAD_EXAMPLE_THREADLIB_H
#define PTHREAD_EXAMPLE_THREADLIB_H

#include "common.h"
#include <pthread.h>

// define what data each thread will use
typedef struct
{
    int isDelayedStart; // 0 or 1
    int delay; // seconds
    unsigned id; // 0 - 127
    pthread_t tid;
    char message[MAX_MSG_SIZE];
} ThreadData;

void createThreads(ThreadData* td, int numberOfThreads);
void joinThreads(ThreadData* td, int numberOfThreads);

#endif // PTHREAD_EXAMPLE_THREADLIB_H
