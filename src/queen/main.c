#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char input_cmd[1024];
    FILE *in = stdin;

    while(fgets(input_cmd, sizeof(input_cmd), in) != 0) {
        printf("QUENN введена команда %s", input_cmd);
    }

    return EXIT_SUCCESS;
}