/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    init_cl.h
 **************************************************/

#ifndef _INIT_CL_H_
#define _INIT_CL_H_

#define CL_INIT_SUCCESS   0
#define CL_INIT_NULL_PTR  1
#define CL_INIT_FAIL_INIT 2
#define CL_INIT_NO_DEVICE 3

#include<CL/cl.h>
#include<CL/opencl.h>
#include<CL/cl_ext.h>
#include<CL/cl_gl_ext.h>
#include<CL/cl_platform.h>

int initialize_opencl(cl_platform_id *id);

#endif /* _INIT_CL_H_ */
