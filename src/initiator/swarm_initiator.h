#pragma once

#define QUEEN "queen"

/* Структура конфигурации приложения */
struct app_config {
    char *path_queen;
};

/**
 * Печать справки по приложению.
 */
void print_help();

/** 
 * Проверка количества аргументов, если количество аргументов меньше 1, будет выполнен выход и возврат ошибки.
 * @param arg_count количество аргументов.
 */
void checking_for_arguments(int arg_count);

/**
 * Обработка аргументов приложения.
 * @param arg_count количество аргументов.
 * @param arg_values массив аргументов.
 * @return структуру app_config, память под которую нужно после использования освободить с помощью free.
 */
struct app_config *prepare_arguments(int arg_count, char **arg_values);