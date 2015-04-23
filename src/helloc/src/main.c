#include <stdlib.h>
#include <stdio.h>

#include "commander/commander.h"

/*
 * Program version.
 */

#define VERSION "0.0.1"


/*
 * helloc.
 */

typedef struct {
    const char *name;
    int count;
} helloc_t;

/*
 * helloc instance.
 */

static helloc_t helloc;

/*
 * Output error `msg`.
 */

void
error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

/*
 * --count <value>
 */

static void on_count(command_t *self) {
    helloc_t *helloc = (helloc_t *) self->data;
    helloc->count = atoi(self->arg);
}

/*
 * --name <name>
 */

static void on_name(command_t *self) {
    helloc_t *helloc = (helloc_t *) self->data;
    helloc->name = self->arg;
}

/*
 * Entry point.
 */

int main (int argc, char * argv[]) {
    /* defaults */

    helloc.name   = "World";
    helloc.count  = 1;


    /* program */

    command_t program;
    command_init(&program, "helloc", VERSION);
    program.data = &helloc;
    program.usage = "[options]";
    command_option(&program, "-c", "--count <value>", "Number of times to say hello [1]", on_count);
    command_option(&program, "-n", "--name <name>", "Your name [World]", on_name);
    command_parse(&program, argc, argv);
    command_free(&program);


    /* ready */


    for (int i = 0 ; i < helloc.count; i++) {
        printf("Hello %s!\n", helloc.name);
    }

    return EXIT_SUCCESS;
}