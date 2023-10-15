#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *env_variable_name = "MY_VARIABLE";
    char *env_variable_value = "Hello, World!";

    if (setenv(env_variable_name, env_variable_value, 1) != 0) {
        perror("setenv");
        return EXIT_FAILURE;
    }

    char *env_value = getenv(env_variable_name);
    if (env_value != NULL) {
        printf("environment variable %s has value: %s\n", env_variable_name, env_value);
    } else {
        printf("environment variable %s has no value.\n", env_variable_name);
    }

    if (unsetenv(env_variable_name) != 0) {
        perror("unsetenv");
        return EXIT_FAILURE;
    }

    env_value = getenv(env_variable_name);
    if (env_value != NULL) {
        printf("environment variable %s has value: %s\n", env_variable_name, env_value);
    } else {
        printf("environment variable %s has no value after deleting.\n", env_variable_name);
    }

    return EXIT_SUCCESS;
}
