//
// Created by vboxuser on 10/15/23.
//
#ifndef ENVIRON_H
#define ENVIRON_H

void display_environment();
void display_help();
void display_variable_info(char *variable);
void set_variable_value(char *variable, char *value);
void assign_variable_value(char *variable, char *value);
void delete_variable(char *variable);
void clear_environment();

#endif
