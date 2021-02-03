#include "log.h"

/**
 * Make_message - this function create a string
 * with this format:
 *
 * [Ddd Mmm Yyy] [hh:mm AM/PM]\n
 * Message\n\n
 *
 * @message: Input string obtained from ARGV[1]
 * the size of message ONLY 140 characters
 *
 * note: in future versions i will try to make
 * an option for modify time format in a dotfile
 * but not is a promise
 *
 * for greater ease of the program only a
 * single argument is used (if you want create
 * a text use quotes)
 *
 * Return: return all message ready to dump in a
 * file
 * **/


char *Make_message(char *message) {
    time_t rawtime;
    struct tm * timeinfo;
    char *buffer = NULL;

    buffer = calloc(170, sizeof(char));

    time(&rawtime);

    timeinfo = localtime(&rawtime);

    strftime(buffer, 28, "[%a %b %Y] [%I:%M %p]\n", timeinfo);

    strcat(strcat(buffer, message), "\n\n");
    return (buffer);
}
