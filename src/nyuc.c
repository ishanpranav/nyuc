// Licensed under the MIT license.

#include <ctype.h>
#include <stdio.h>
#include "argmanip.h"

int main(int argc, const char* const* argv)
{
    char** upperArgs = manipulate_args(argc, argv, toupper);
    char** lowerArgs = manipulate_args(argc, argv, tolower);

    for (char* const* p = upperArgs, * const* q = lowerArgs;
        *p && *q;
        ++argv, ++p, ++q)
    {
        printf("[%s] -> [%s] [%s]\n", *argv, *p, *q);
    }

    free_copied_args(upperArgs, lowerArgs, NULL);
}
