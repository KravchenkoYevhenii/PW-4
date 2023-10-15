//
// Created by vboxuser on 10/15/23.
//

#include <stdio.h>
#include <string.h>
#include "environ.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        display_environment();
    } else if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            display_help();
        } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
            clear_environment();
        } else {
            printf("Invalid option. Use -h or --help for usage information.\n");
        }
    } else if (argc == 3) {
        if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0) {
            display_variable_info(argv[2]);
        } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0) {
            delete_variable(argv[2]);
        } else {
            printf("Invalid option. Use -h or --help for usage information.\n");
        }
    } else if (argc == 4) {
        if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) {
            set_variable_value(argv[2], argv[3]);
        } else {
            printf("Invalid option. Use -h or --help for usage information.\n");
        }
    } else if (argc == 5) {
        if ((strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--assign") == 0) &&
            (strcmp(argv[3], "-v") == 0 || strcmp(argv[3], "--value") == 0)) {
            assign_variable_value(argv[2], argv[4]);
        } else {
            printf("Invalid option. Use -h or --help for usage information.\n");
        }
    } else {
        printf("Invalid number of arguments. Use -h or --help for usage information.\n");
    }

    return 0;
}
