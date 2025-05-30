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

#include "commandInterpreter.h"
#include "threadLib.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// License for command line interfaces. Formatted to play nice with 80 character wide terminals.
static char* license = "Copyright (C) 2015 Douglas Chidester. This program comes with ABSOLUTELY\n\
NO WARRANTY; This is free software, and you are welcome to redistribute it under\ncertain conditions.\n";

static void setRandomStartDelayForAllThreads(ThreadData* tdArray, int arrayLength);
static void setRandomThreadStartDelay(ThreadData* td);
static void setDefaultMessageForAllThreads(ThreadData* tdArray, int arrayLength);

int main(int argc, char* argv[])
{
    srand(time(NULL)); // seed random number generator
    int threads;
    ThreadData td[MAX_NUMBER_OF_THREADS];

    puts(license); // show GPL at start of program output

    threads = promptForMoreThreads();

    // set thread default values
    setRandomStartDelayForAllThreads(td, threads);
    setDefaultMessageForAllThreads(td, threads);

    createThreads(td, threads);

    puts("Main thread created all child threads..");

    joinThreads(td, threads);

    puts("Main thread joined all child threads. Now exiting.\n");

    return 0;
}

static void setRandomStartDelayForAllThreads(ThreadData* tdArray, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        setRandomThreadStartDelay(&tdArray[i]);
    }
}

static void setRandomThreadStartDelay(ThreadData* td)
{
    const int maxSleepNonInclusive = 6; // seconds
    td->delay = rand() % maxSleepNonInclusive;
}

static void setDefaultMessageForAllThreads(ThreadData* tdArray, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        strncpy(tdArray[i].message, "Default thread message.", (size_t)MAX_MSG_SIZE);
    }
}
