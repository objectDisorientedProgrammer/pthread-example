/*
	Example program to demonstrate pthreads.
    Copyright (C) 2015-2019  Douglas Chidester

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

// license for command line interfaces
static char* license = "Copyright (C) 2015 Douglas Chidester. This program comes with\nABSOLUTELY NO WARRANTY;\
                This is free software, and you are welcome to\nredistribute it under certain conditions.\n";

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

