/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                     config.c
 **************************************************/

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

#include <cjson/cJSON.h>

#include "config.h"
#include "load_shader.h"

static struct cJSON *config_json = NULL;

int config_file_init(const char *filepath)
{
    int retcode = CONFIG_SUCCESS;
    FILE *fd = NULL;
    char *buffer = NULL;
    int filesize = 0;

    if(filepath == NULL)
    {
        retcode = CONFIG_NULL_PTR;
        goto CLEANUP;
    }

    /* Acquire file size */
    fd = fopen(filepath, "r");
    if(fd == NULL)
    {
        retcode = CONFIG_FOPEN_FAIL;
        goto CLEANUP;
    }

    fseek(fd, 0, SEEK_END);
    filesize = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    buffer = malloc(sizeof(char) * (filesize+1));
    if(buffer == NULL)
    {
        retcode = CONFIG_BAD_ALLOC;
        goto CLEANUP;
    }

CLEANUP:
    if(buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
    }
    return retcode;
}

int config_file_cleanup()
{
    int retcode = CONFIG_SUCCESS;

    return retcode;
}

int config_print_error(FILE *fd, int errorcode)
{
    int retcode = CONFIG_SUCCESS;

    switch(errorcode)
    {
        case CONFIG_SUCCESS:
            fprintf(fd, "Configuration - No error in call.\n");
            break;
        case CONFIG_NULL_PTR:
            fprintf(fd, "Configuration call passed a NULL pointer.\n");
            break;
        case CONFIG_FOPEN_FAIL:
            fprintf(fd, "Configuration file failed to open.\n");
            break;
        case CONFIG_BAD_ALLOC:
            fprintf(fd, "Configuration function failed to acquire memory.\n");
            break;
        default:
            fprintf(fd, "Configuration error code not defined.\n");
            break;
    }

    return retcode;
}
