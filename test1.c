#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <terminals.h>

int
main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);

    sleep(2000);

    exit(0);
}
