/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                     main.c
 **************************************************/

/* C standard headers */
#include <stdio.h>
#include <stdlib.h>

/* OpenCL headers */
#include <CL/cl.h>
#include <CL/opencl.h>

/* OpenGL headers */
#include <GL/glew.h>

/* GLFW headers */
#include <GLFW/glfw3.h>

/* Local headers */
#include "load_cl.h"

#define INIT_OPENCL_SUCCESS   0
#define INIT_OPENCL_FAILURE   1
#define INIT_OPENCL_NO_DEVICE 2

void print_usage();
int initialize_opencl(cl_platform_id *id);

int main(int argc, char **argv)
{
    GLFWwindow *window = NULL;
    cl_platform_id platform;

    char *kernel_file = NULL;
    char *kernel_data = NULL;
    int kernel_size = 0;

    FILE *fd = NULL;

    int retval = 0;
    int rcode = 0;


    /* Check for appropriate arguments */
    if(argc < 2)
    {
        print_usage();
        retval = 1;
        goto CLEANUP;
    }
    else
    {
        kernel_file = argv[1];
    }

    /* Initialize OpenCL */
    rcode = initialize_opencl(&platform);

    if(rcode != INIT_OPENCL_SUCCESS)
    {
        fprintf(stderr, "Error - OpenCL failed to initialize.\n");
        retval = 1;
        goto CLEANUP;
    }
    

    fprintf(stdout, "Loading kernel %s\n", kernel_file);

    kernel_size = get_filesize(kernel_file);

    /* Check if file opened correctly while acquiring the size */
    if(kernel_size < 0)
    {
        fprintf(stderr, "Error opening kernel file %s\n", kernel_file);
        retval = 1;
        goto CLEANUP;
    }

    kernel_data = load_cl_source(kernel_file, kernel_size);

    if(kernel_data == NULL)
    {
        fprintf(stderr, "Failure to allocate %d bytes of memory\n",
                kernel_size);
        retval = 1;
        goto CLEANUP;
    }

    /* Compile kernel */

CLEANUP:
    if(fd != NULL)
    {
        fclose(fd);
        fd = NULL;
    }
    if(kernel_data != NULL)
    {
        free(kernel_data);
        kernel_data = NULL;
    }
    return retval;
}

void print_usage()
{
    fprintf(stdout, "Usage: ./run {kernel-file}\n");
}

int initialize_opencl(cl_platform_id *id)
{
    int retval = 0;
    cl_int result = 0;
    cl_platform_id platform;
    cl_uint ndevices = 0u;

    result = clGetPlatformIDs(0, NULL, &ndevices);

    if(result != CL_SUCCESS)
    {
        retval = INIT_OPENCL_FAILURE;
        goto CLEANUP;
    }
    else if(ndevices == 0u)
    {
        retval = INIT_OPENCL_NO_DEVICE;
        goto CLEANUP;
    }

    result = clGetPlatformIDs(1, &platform, NULL);
    if(result != CL_SUCCESS)
    {
        retval = INIT_OPENCL_FAILURE;
        goto CLEANUP;
    }

    *id = platform;

CLEANUP:
    return retval;
}
