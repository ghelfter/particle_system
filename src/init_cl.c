/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    init_cl.c
 **************************************************/

#include <stdio.h>

#include "init_cl.h"

int initialize_opencl(cl_platform_id *id)
{
    int retcode = CL_INIT_SUCCESS;
    cl_int result = 0;
    cl_platform_id platform;
    cl_uint ndevices = 0u;

    if(id == NULL)
    {
        retcode = CL_INIT_NULL_PTR;
        goto CLEANUP;
    }

    result = clGetPlatformIDs(0, NULL, &ndevices);

    fprintf(stdout, "There are %u devices available.\n", ndevices);

    if(result != CL_SUCCESS)
    {
        retcode = CL_INIT_FAIL_INIT;
        goto CLEANUP;
    }
    else if(ndevices == 0u)
    {
        retcode = CL_INIT_NO_DEVICE;
        goto CLEANUP;
    }

    result = clGetPlatformIDs(1, &platform, NULL);
    if(result != CL_SUCCESS)
    {
        retcode = CL_INIT_FAIL_INIT;
        goto CLEANUP;
    }

    *id = platform;

CLEANUP:
    return retcode;
}
