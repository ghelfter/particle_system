/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                  load_shader.c
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "load_shader.h"

int get_filesize(const char *fname)
{
    FILE *fd = NULL;
    int result = 0;

    fd = fopen(fname, "r");

    if(fd == NULL)
    {
        result = -1;
    }

    else
    {
        fseek(fd, 0, SEEK_END);
        result = ftell(fd);
        fclose(fd);
    }

    return result;
}

char* load_shader_source(const char *fname, int filesize)
{
    FILE *fd = NULL;
    char *res = NULL;

    res = malloc(sizeof(char) * (filesize + 1));

    fd = fopen(fname, "r");

    fread(res, sizeof(char), filesize, fd);
    res[filesize] = '\0';

#ifdef DEBUG
    fprintf(stdout, "%s\n", res);
#endif

    fclose(fd);

    fd = NULL;

    return res;
}
