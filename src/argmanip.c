// argmanip.c
// Copyright (c) 2024 Ishan Pranav
// Licensed under the MIT license.

// CONSTRAINT: must use `malloc`, cannot use `calloc` or other allocators.

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "argmanip.h"

typedef int (* const Manipulator)(int);

char** manipulate_args(
    int count,
    const char* const* args,
    Manipulator manipulator)
{
    char** result = malloc((count + 1) * sizeof(char*));

    for (int i = 0; i < count; i++)
    {
        size_t length = strlen(args[i]);

        result[i] = malloc(length + 1);

        for (size_t j = 0; j < length; j++)
        {
            result[i][j] = manipulator(args[i][j]);
        }

        result[i][length] = '\0';
    }

    result[count] = NULL;

    return result;
}

void free_copied_args(char** args, ...)
{
    va_list argl;

    for (va_start(argl, args); args; args = va_arg(argl, char**))
    {
        for (char** arg = args; *arg; arg++)
        {
            free(*arg);
        }

        free(args);
    }

    va_end(argl);
}
