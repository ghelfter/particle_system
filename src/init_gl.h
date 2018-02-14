/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    init_gl.h
 **************************************************/

#ifndef _INIT_GL_H_
#define _INIT_GL_H_

#include <GLFW/glfw3.h>

#define GL_INIT_SUCCESS   0
#define GL_INIT_NULL_PTR  1
#define GL_INIT_FAIL_INIT 2
#define GL_INIT_NO_WINDOW 3

int initialize_glfw(GLFWwindow **window, int w, int h, const char *title);
int cleanup_glfw(GLFWwindow **window);

#endif /* _INIT_GL_H_ */
