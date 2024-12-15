#include <stdio.h>
#include <stdlib.h>

#include "./swarm_send.h"
#include "./swarm_common.h"

/**
 * Отправка команды через трубу.
 * @param command команда на исполнение.
 * @param path путь для открытия трубы.
 */
void swarm_send_command(char *command, char *path) {
    FILE *output = popen(path, "w");
    if (!output) {
        fprintf(ERR, "Ошибка пути для открытия трубы %s.\n", path);
        exit(EXIT_FAILURE);
    }

    fprintf(output, "%s", command);
    if (ferror(output)) {
        fprintf(ERR, "Ошибка передачи команды %s.\n", command);
        exit(EXIT_FAILURE);
    }

    pclose(output);
}