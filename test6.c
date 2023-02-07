#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
void writer2(void *);
void writer3(void *);
void writer4(void *);
void writer5(void *);
void writer6(void *);
void writer7(void *);
void writer8(void *);

char string1[] = "abcdefghijklmnopqrstuvwxyz\n";
int length1 = sizeof(string1) - 1;

char string2[] = "0123456789\n";
int length2 = sizeof(string2) - 1;

int
main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);
    InitTerminal(3);
    InitTerminal(0);
    sleep(5);

    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer3, NULL);
    ThreadCreate(writer4, NULL);
    ThreadCreate(writer5, NULL);
    ThreadCreate(writer6, NULL);
    ThreadCreate(writer7, NULL);
    ThreadCreate(writer8, NULL);

    ThreadWaitAll();

    exit(0);
}

void
writer1(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(1, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}

void
writer2(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(1, string2, length2);
    if (status != length2)
	fprintf(stderr, "Error: writer2 status = %d, length2 = %d\n",
	    status, length2);
}

void
writer3(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(2, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}

void
writer4(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(2, string2, length2);
    if (status != length2)
	fprintf(stderr, "Error: writer2 status = %d, length2 = %d\n",
	    status, length2);
}

void
writer5(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(3, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}

void
writer6(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(3, string2, length2);
    if (status != length2)
	fprintf(stderr, "Error: writer2 status = %d, length2 = %d\n",
	    status, length2);
}

void
writer7(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(0, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}

void
writer8(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(0, string2, length2);
    if (status != length2)
	fprintf(stderr, "Error: writer2 status = %d, length2 = %d\n",
	    status, length2);
}