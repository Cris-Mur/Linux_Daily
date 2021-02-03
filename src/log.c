#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * log - this program generate string
 * with the time and a message this
 * string will save in a file in
 * $HOME/daily.
 * this file was created in 600 mode
 * that only owner user can write
 * and read.
 *
 * @argc:  argument counter
 * @argv:  argument vector
 *
 * Help: usage: log 'message'
 *
 * Return: Allways return 0
 *
 **/

int main(int argc, char **argv) {

    char *log = NULL, *home = NULL;

    if (getuid() != geteuid() || geteuid() <= 0) {
        printf("[ERROR]: this program is not for root user sorry :C\n");
        exit (1);
    }

    if (argc != 2) {
        printf("USAGE: log 'mesagge'\n\tDONT FORGET USE QUOTES\n");
        return (1);
    }

    log = Make_message(argv[1]);

    home = calloc(100, sizeof(char));
    strcat(strcat(home, getenv("HOME")), "/daily");

    write_in_file(home, log);

    return (0);
}
