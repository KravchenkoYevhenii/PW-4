#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <variable_name> <value>\n", argv[0]);
        return 1;
    }

    const char *variable_name = argv[1];
    const char *value = argv[2];

    if (setenv(variable_name, value, 1) == 0) {
        char *env_value = getenv(variable_name);
        if (env_value != NULL) {
            printf("environment variable %s: %s\n", variable_name, env_value);
        } else {
            printf("environment variable %s doesn't exist\n", variable_name);
        }

    }
    else {
        perror("setenv");
        return 1;
    }
    return 0;
}