#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>

void writer(void *);

char string[] = "abcdefghijklmn\nopqrstuvwxyz";
int length = sizeof(string) - 1;

int main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);

    ThreadCreate(writer, NULL);

    ThreadWaitAll();

    exit(0);
}

void
writer(void *arg)
{
    (void) arg;
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(1, string, length);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}
