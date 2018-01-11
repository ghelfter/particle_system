/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    load_cl.h
 **************************************************/

#ifndef _LOAD_CL_H_
#define _LOAD_CL_H_

int get_filesize(const char *fname);
char* load_cl_source(const char *fname, int filesize);

#endif /* _LOAD_CL_H_ */
