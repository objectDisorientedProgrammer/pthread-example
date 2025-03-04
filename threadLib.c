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

#include "threadLib.h"
//#include <stdio.h> // for thread task
#include <string.h>
#include <unistd.h>

static void displayHelp(void);
static void errorHandle(const char* msg);
static void* threadFunction(void* arg);

/* Exported (public) functions */

// Create all threads and catch errors
void createThreads(ThreadData* td, int numberOfThreads)
{
    //char tMsg[MSG_SIZE];

    for(unsigned i = 0; i < numberOfThreads; ++i)
    {
        td[i].id = i+1;

        //strncpy(td[i].message, tMsg, (size_t)MSG_SIZE);

        if(pthread_create(&td[i].tid, NULL, threadFunction, &td[i]))
            errorHandle("Error creating thread");
    }
}

// Collect finished threads and catch errors
void joinThreads(ThreadData* td, int numberOfThreads)
{
    for(unsigned j = 0; j < numberOfThreads; ++j)
        if(pthread_join(td[j].tid, NULL))
            errorHandle("Error joining thread");
}

/* Local functions */

// Each thread executes this function
void* threadFunction(void* arg)
{
    ThreadData* data = (ThreadData*) arg;

    char str[8] = "seconds";
    if (data->isDelayedStart)
    {
        // change "seconds" to "second" if delay is 1 second.
        if (data->delay == 1)
            str[6] = '\0';
        sleep(data->delay);
    }

    printf("[%ld, %3d] Woke up after %d %s. %s\n", data->tid, data->id, data->delay, str, data->message);

    pthread_exit(0);
}

