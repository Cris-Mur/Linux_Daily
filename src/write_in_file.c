#include "log.h"

/**
 * write_in_file - this function open and/or create
 * a file where dump information in apend mode,
 * the file is created in 600 mode.
 *
 * @file_path: this contain full path of the file
 * @message: this contain content that write in a
 * file
 *
 * Return: 1 if all okay | -1 if not
 **/


int write_in_file (const char *file_path, char *message) {
    int File_descriptor, aux, open_value;

    if (file_path) {
        File_descriptor = open(file_path, O_CREAT | O_WRONLY | O_APPEND, 0600);

        if (File_descriptor <= 1)
            return (-1);

        open_value = File_descriptor;

        aux = strlen(message);

        File_descriptor = write(File_descriptor, message, aux);
        close(File_descriptor);
        if (File_descriptor == open_value) {
            return (1);
        } else {
            return (-1);
        }
    }
    return (-1); /*error value*/
}
