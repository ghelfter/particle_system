/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                     main.c
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <CL/cl.h>
#include <CL/opencl.h>

void print_usage();

int main(int argc, char **argv)
{
    char *kernel_file = NULL;

    if(argc < 2)
    {
        print_usage();
        exit(1);
    }
    else
    {
        kernel_file = argv[1];
    }

    fprintf(stdout, "Loading kernel %s\n", kernel_file);

    return 0;
}

void print_usage()
{
    fprintf(stdout, "Usage: ./run {kernel-file}\n");
}
