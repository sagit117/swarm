#pragma once

/**
 * Отправка команды через трубу.
 * @param command команда на исполнение.
 * @param path путь для открытия трубы.
 */
void swarm_send_command(char *command, char *path);