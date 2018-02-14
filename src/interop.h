/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    interop.h
 **************************************************/

#ifndef _INTEROP_H_
#define _INTEROP_H_

#include <GL/glew.h>
#include<CL/cl.h>
#include<CL/opencl.h>
#include<CL/cl_ext.h>
#include<CL/cl_gl_ext.h>
#include<CL/cl_platform.h>

#define INTEROP_SUCCESS   0
#define INTEROP_NULL_PTR  1
#define INTEROP_BAD_ALLOC 2

int create_cl_ro_mem(cl_context *context, cl_mem *mem, GLuint texture);
int create_cl_wo_mem(cl_context *context, cl_mem *mem, GLuint texture);
int create_cl_rw_mem(cl_context *context, cl_mem *mem, GLuint texture);

int interrupt_for_kernel(cl_command_queue cq, cl_kernel kernel,
                         cl_mem mem);

#endif /* _INTEROP_H_ */
