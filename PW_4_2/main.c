#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    const char *env_name = argv[1];
    char *env_value = getenv(env_name);

    if (env_value == NULL) {
        printf("environment variable with this name \"%s\" doesn't exist.\n", env_name);
    } else if (env_value[0] == '\0') {
        printf("environment variable with this name \"%s\" exists but value isn't defined.\n", env_name);
    } else {
        printf("environment variable with this name \"%s\" has value: %s\n", env_name, env_value);
    }

    return 0;
}