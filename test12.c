#include <hardware.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <threads.h>
#include <terminals.h>
void reader1(void *);
void reader2(void *);
void reader3(void *);
void reader4(void *);
void writer1(void *);
void writer2(void *);


char string[] = "abcdefghijklmnopqrstuvwxyz";
int length = sizeof(string) - 1;

int main(int argc, char **argv)
{   
    (void) argc; 
    (void) argv;

    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);

    sleep(5);

    struct termstat *stats = malloc(NUM_TERMINALS * sizeof(struct termstat));

    ThreadCreate(reader1, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(reader3, NULL);
    ThreadCreate(reader4, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);

    sleep(10);
    TerminalDriverStatistics(stats);
    int term;
    for (term = 0; term < NUM_TERMINALS; term++) {
        printf("Terminal Number: %d\n", term);
        printf("tty_in: %d\n", stats[term].tty_in);
        printf("tty_out: %d\n", stats[term].tty_out);
        printf("tty_out: %d\n", stats[term].user_in);
        printf("tty_out: %d\n", stats[term].user_out);
    }
    sleep(10);
    TerminalDriverStatistics(stats);
    for (term = 0; term < NUM_TERMINALS; term++) {
        printf("Terminal Number: %d\n", term);
        printf("tty_in: %d\n", stats[term].tty_in);
        printf("tty_out: %d\n", stats[term].tty_out);
        printf("tty_out: %d\n", stats[term].user_in);
        printf("tty_out: %d\n", stats[term].user_out);
    }
    
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
    status = ReadTerminal(1, buf, 10);
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
    status = ReadTerminal(1, buf, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader3(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(2, buf, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader4(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(2, buf, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
writer1(void *arg)
{
    (void) arg;
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(1, string, length);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
writer2(void *arg)
{
    (void) arg;
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(2, string, length);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}
