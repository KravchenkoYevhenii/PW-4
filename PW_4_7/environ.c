//
// Created by vboxuser on 10/15/23.
//

#include "environ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void display_environment() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

void display_help() {
    // Вивести інформацію щодо роботи з програмою
    printf("Usage: environ [OPTIONS]\n");
    printf("-h, --help                   Display help\n");
    printf("-i, --info <variable>        Display value of the specified variable\n");
    printf("-s, --set <variable=value>   Set value for the specified variable\n");
    printf("-a, --assign <variable>      Assign value to the specified variable\n");
    printf("-v, --value <value>          Value for assigning variable (optional)\n");
    printf("-d, --del <variable>         Delete the specified variable\n");
    printf("-c, --clear                  Clear the environment\n");
}

void display_variable_info(char *variable) {
    char *value = getenv(variable);
    if (value != NULL) {
        printf("Variable %s has value: %s\n", variable, value);
    } else {
        printf("Variable %s not found in the environment.\n", variable);
    }
}

void set_variable_value(char *variable, char *value) {
    if (setenv(variable, value, 1) == 0) {
        printf("Variable %s set to %s\n", variable, value);
    } else {
        perror("Error setting variable");
    }
}

void assign_variable_value(char *variable, char *value) {
    if (value == NULL) {
        value = ""; // Assign an empty string if value is not specified
    }
    if (setenv(variable, value, 1) == 0) {
        printf("Variable %s assigned value: %s\n", variable, value);
    } else {
        perror("Error assigning variable");
    }
}

void delete_variable(char *variable) {
    if (unsetenv(variable) == 0) {
        printf("Variable %s deleted from the environment\n", variable);
    } else {
        perror("Error deleting variable");
    }
}

void clear_environment() {
    clearenv();
    printf("Environment cleared\n");
}
