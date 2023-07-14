#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

/** This file contains the prototype functions of the program.*/
/** The prototypes functions start here.*/

void print_arguments(char *argv[], int argc);
void print_str(char *str);

#endif /* MAIN_H */
