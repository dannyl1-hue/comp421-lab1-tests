#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader1(void *);
void reader2(void *);
void reader3(void *);
void reader4(void *);

int main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);

    sleep(5);

    ThreadCreate(reader1, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(reader3, NULL);
    ThreadCreate(reader4, NULL);


    ThreadWaitAll();

    exit(0);
}

void
reader1(void *arg)
{
    (void) arg;
    int status;
    char buf1[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf1, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf1[i]);
    }
    printf("\n");
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader2(void *arg)
{
    (void) arg;
    int status;
    char buf2[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf2, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf2[i]);
    }
    printf("\n");
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader3(void *arg)
{
    (void) arg;
    int status;
    char buf3[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(2, buf3, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf3[i]);
    }
    printf("\n");
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader4(void *arg)
{
    (void) arg;
    int status;
    char buf4[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(2, buf4, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf4[i]);
    }
    printf("\n");
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}