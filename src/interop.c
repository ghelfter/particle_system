/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    interop.c
 **************************************************/

#include "interop.h"

static int create_cl_mem(cl_context *context, cl_mem *mem,
                         cl_mem_flags flags);

int create_cl_ro_mem(cl_context *context, cl_mem *mem)
{
    return create_cl_mem(context, mem, CL_MEM_READ_ONLY);
}

int create_cl_wo_mem(cl_context *context, cl_mem *mem)
{
    return create_cl_mem(context, mem, CL_MEM_WRITE_ONLY);
}

int create_cl_rw_mem(cl_context *context, cl_mem *mem)
{
    return create_cl_mem(context, mem, CL_MEM_READ_WRITE);
}

static int create_cl_mem(cl_context *context, cl_mem *mem,
                         cl_mem_flags flags)
{
    int retcode = INTEROP_SUCCESS;
    cl_mem t_mem = NULL;

    if(context == NULL || mem == NULL)
    {
        retcode = INTEROP_NULL_PTR;
    }

    return retcode;
}
