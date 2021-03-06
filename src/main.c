/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                     main.c
 **************************************************/

/* C standard headers */
#include <stdio.h>
#include <stdlib.h>

/* OpenGL headers */
#include <GL/glew.h>

/* GLFW headers */
#include <GLFW/glfw3.h>

/* OpenCL headers */
#include <CL/cl.h>
#include <CL/opencl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl_ext.h>
#include <CL/cl_platform.h>

/* Local headers */
#include "load_shader.h"
#include "init_gl.h"
#include "init_cl.h"

#define INIT_OPENCL_SUCCESS   0
#define INIT_OPENCL_FAILURE   1
#define INIT_OPENCL_NO_DEVICE 2

#define WIDTH 640
#define HEIGHT 480
#define TITLE "Particle Simulation"

void print_usage(FILE *fd);

int main(int argc, char **argv)
{
    GLFWwindow *window = NULL;
    cl_platform_id platform;

    char *kernel_file = NULL;
    char *kernel_data = NULL;
    int kernel_size = 0;

    FILE *fd = NULL;

    int retval = EXIT_SUCCESS;
    int rcode = 0;


    /* Check for appropriate arguments */
    if(argc < 2)
    {
        print_usage(stdout);
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }
    else
    {
        kernel_file = argv[1];
    }

    rcode = initialize_glfw(&window, WIDTH, HEIGHT, TITLE);
    if(rcode != GL_INIT_SUCCESS)
    {
        fprintf(stderr, "Error - GLFW failed to initialize.\n");
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }

    rcode = initialize_glew();
    if(rcode != GL_INIT_SUCCESS)
    {
        fprintf(stderr, "Error - GLEW failed to initialize.\n");
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }

    /* Initialize OpenCL */
    rcode = initialize_opencl(&platform);

    if(rcode != INIT_OPENCL_SUCCESS)
    {
        fprintf(stderr, "Error - OpenCL failed to initialize.\n");
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }
    

    fprintf(stdout, "Loading kernel %s\n", kernel_file);

    kernel_size = get_filesize(kernel_file);

    /* Check if file opened correctly while acquiring the size */
    if(kernel_size < 0)
    {
        fprintf(stderr, "Error opening kernel file %s\n", kernel_file);
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }

    kernel_data = load_shader_source(kernel_file, kernel_size);

    if(kernel_data == NULL)
    {
        fprintf(stderr, "Failure to allocate %d bytes of memory\n",
                kernel_size);
        retval = EXIT_FAILURE;
        goto CLEANUP;
    }

    /* Compile kernel */

    /* Perform main application loop */
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

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

    cleanup_glfw(&window);

    return retval;
}

void print_usage(FILE *fd)
{
    fprintf(fd, "Usage: ./run {kernel-file}\n");
}
