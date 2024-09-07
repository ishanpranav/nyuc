// Licensed under the MIT license.

#ifndef _ARGMANIP_H_
#define _ARGMANIP_H_

char** manipulate_args(
    int count,
    const char* const* args,
    int (* const manipulator)(int));

void free_copied_args(char** args, ...);

#endif
