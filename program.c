/*
    Example program to demonstrate pthreads.
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

#include "program.h"

static void displayHelp(void);

int main(int argc, char* argv[])
{
    int threads;
    ThreadData td[MAX_NUMBER_OF_THREADS];

    puts(license); // show GPL at start of program output

    threads = promptForMoreThreads();
    createThreads(td, threads);

    puts("Main thread created all child threads..");

    joinThreads(td, threads);

    puts("Main thread joined all child threads. Now exiting.\n");

    return 0;
}

// Print an error message to stderr
void errorHandle(const char* msg)
{
    fprintf(stderr, "%s", msg);
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

    for(int8 i = 0; i < numberOfThreads; ++i)
    {
        td[i].id = i+1;
        strncpy(td[i].message, tMsg, (size_t)MSG_SIZE);
        if(pthread_create(&td[i].tid, NULL, threadFunction, &td[i]))
            errorHandle("Error creating thread");
    }
}

// Collect finished threads and catch errors
void joinThreads(ThreadData* td, int numberOfThreads)
{
    for(int8 j = 0; j < numberOfThreads; ++j)
        if(pthread_join(td[j].tid, NULL))
            errorHandle("Error joining thread");
}

// Let the user change number of threads created if desired
int promptForMoreThreads(void)
{
    char response[MSG_SIZE];
    int numThrds;
    // prompt user
    printf("Would you like to change the number of threads created? (y/N) ");
    fgets(response, MSG_SIZE, stdin);

    switch(*response)
    {
        case 'y':
        case 'Y':
            // get new number of threads
            printf("Please enter the number of threads you would like (1-100): ");
            numThrds = atoi(fgets(response, MSG_SIZE, stdin));

            // make sure new number is within limits
            if(numThrds < MIN_NUMBER_OF_THREADS)
                numThrds = MIN_NUMBER_OF_THREADS;
            else if(numThrds > MAX_NUMBER_OF_THREADS)
                numThrds = MAX_NUMBER_OF_THREADS;
            break;
        default:
            numThrds = DEFAULT_NUM_THREADS;
            break;
    }

    return numThrds;
}

// Let the user change the thread message if desired
void promptForNewMessage(char* msg)
{
    printf("Would you like to change the thread message? (y/N) ");
    fgets(msg, MSG_SIZE, stdin);

    switch(*msg)
    {
        case 'y':
        case 'Y':
            // get new number of threads
            printf("Please enter a new message:\n    ");
            if(fgets(msg, MSG_SIZE, stdin) == NULL)
                errorHandle("No new message was entered.\n");

            // remove extra newline
            char* last = strrchr(msg, '\n');
            *last = '\0';
            break;
        default:
            // default return value
            strcpy(msg, "Hello from this thread.");
            break;
    }
}

void displayHelp(void)
{
    puts("\nUsage: runner [threadCount]");
}
