/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    interop.c
 **************************************************/

#include "interop.h"

static int create_cl_mem(cl_context *context, cl_mem *mem,
                         cl_mem_flags flags, GLuint texture);

int create_cl_ro_mem(cl_context *context, cl_mem *mem, GLuint texture)
{
    return create_cl_mem(context, mem, CL_MEM_READ_ONLY, texture);
}

int create_cl_wo_mem(cl_context *context, cl_mem *mem, GLuint texture)
{
    return create_cl_mem(context, mem, CL_MEM_WRITE_ONLY, texture);
}

int create_cl_rw_mem(cl_context *context, cl_mem *mem, GLuint texture)
{
    return create_cl_mem(context, mem, CL_MEM_READ_WRITE, texture);
}

int interrupt_for_kernel(cl_command_queue cq, cl_kernel kernel,
                         cl_mem mem)
{
    int retcode = INTEROP_SUCCESS;

    if(cq == NULL || kernel == NULL || mem == NULL)
    {
        retcode = INTEROP_NULL_PTR;
    }
    else
    {
        glFinish();
    }

    return retcode;
}

static int create_cl_mem(cl_context *context, cl_mem *mem,
                         cl_mem_flags flags, GLuint texture)
{
    int retcode = INTEROP_SUCCESS;
    cl_mem t_mem = NULL;

    if(context == NULL || mem == NULL)
    {
        retcode = INTEROP_NULL_PTR;
    }
    else
    {
        t_mem = clCreateFromGLTexture(*context, flags, GL_TEXTURE_2D,
                                      0, texture, NULL);

        if(t_mem == NULL)
        {
            retcode = INTEROP_BAD_ALLOC;
        }
        else
        {
            *mem = t_mem;
            t_mem = NULL;
        }
    }

    return retcode;
}
