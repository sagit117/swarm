#include <stdio.h>      // stdin
#include <stdlib.h>     // EXIT_SUCCESS
#include <unistd.h>     // getopt
#include <unistd.h>     // ssize_t

#include "../common/swarm_send.h"
#include "../common/swarm_read_parameter_from_file.h"
#include "../common/swarm_common.h"
#include "./swarm_initiator.h"

int main(int argc, char **argv) {
    checking_for_arguments(argc);
    struct app_config *config = prepare_arguments(argc, argv);
    
    fprintf(OUT, "Ожидаю ввод команды ...\n");
    
    ssize_t read;
    char *line;
    size_t len = 0;

    while((read = getline(&line, &len, IN)) != -1) {
        swarm_send_command(line, config->path_queen);
    }

    free(config);
    return EXIT_SUCCESS;
}

/**
 * Печать справки по приложению.
 */
void print_help() {
    fprintf(OUT, "\
        \nПараметры приложения: \
        \n\t-c: путь до файла конфигурации, пример: -c ./cfg\n"\
    );
}

/** 
 * Проверка количества аргументов, если количество аргументов меньше 1, будет выполнен выход и возврат ошибки.
 * @param arg_count количество аргументов.
 */
void checking_for_arguments(int arg_count) {
    if (arg_count == 1) {
        fprintf(OUT, "Отсутствуют параметры конфигурации!");
        print_help();
        exit(EXIT_FAILURE);
    }
}

/**
 * Обработка аргументов приложения.
 * @param arg_count количество аргументов.
 * @param arg_values массив аргументов.
 * @return структуру app_config, память под которую нужно после использования освободить с помощью free.
 */
struct app_config *prepare_arguments(int arg_count, char **arg_values) {
    int res = 0;
    extern char *optarg;
    extern int optopt;
    extern int opterr;
    opterr = 0; // отключить ошибки в getopt

    struct app_config *config = malloc(sizeof(struct app_config));
    
    while ((res = getopt(arg_count, arg_values, "hc:")) != -1) {
		switch (res) {
            case 'h': 
                print_help();
                exit(EXIT_SUCCESS);
            case 'c': 
                FILE *cfg_file = fopen(optarg, "r");
                if (!cfg_file) {
                    fprintf(ERR, "Ошибка открытия файла конфигурации %s!\n", optarg);
                    exit(EXIT_FAILURE);
                }

                config->path_queen = swarm_read_parameter_from_file(cfg_file, QUEEN);
                if (config->path_queen == NULL) {
                    fprintf(ERR, "Ошибка чтения конфигурации, не найден токен %s\n", QUEEN);
                    exit(EXIT_FAILURE);
                }

                fclose(cfg_file);
                break;
            case '?':
                fprintf(OUT, "Не известный параметр %c", optopt);
                print_help();
                exit(EXIT_FAILURE);
		} 
	}

    return config;
}

