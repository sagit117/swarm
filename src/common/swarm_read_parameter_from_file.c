#include <string.h>
#include <unistd.h> // ssize_t

#include "./swarm_read_parameter_from_file.h"

char *swarm_read_parameter_from_file(FILE *file, char *parameter) {
    ssize_t read;
    char *line;
    size_t len = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, ":");

        if (strcmp(token, parameter) == 0) {
            return strtok(NULL, ":");
        }
    }

    return NULL;
}