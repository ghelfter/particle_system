/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    init_gl.c
 **************************************************/

#include "init_gl.h"

int initialize_glfw(GLFWwindow **window, int w, int h, const char *title)
{
    int retcode = GL_INIT_SUCCESS;
    GLFWwindow *tmp = NULL;

    if(window == NULL || title == NULL)
    {
        retcode = GL_INIT_NULL_PTR;
    }
    else if(!glfwInit())
    {
        retcode = GL_INIT_FAIL_INIT;
    }
    else
    {
        tmp = glfwCreateWindow(w, h, title, NULL, NULL);
        if(tmp == NULL)
        {
            glfwTerminate();
            retcode = GL_INIT_NO_WINDOW;
        }
        else
        {
            glfwMakeContextCurrent(tmp);
            *window = tmp;
        }
    }

    return retcode;
}
