#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader1(void *);
void reader2(void *);

int main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);
    sleep(5);

    ThreadCreate(reader1, NULL);
    ThreadCreate(reader2, NULL);


    ThreadWaitAll();

    exit(0);
}

void
reader1(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf, 100);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader2(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf, 100);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}