/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                    init_gl.c
 **************************************************/

#include <GL/glew.h>

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

int cleanup_glfw(GLFWwindow **window)
{
    int retcode = GL_INIT_SUCCESS;

    if(window == NULL)
    {
        retcode = GL_INIT_NULL_PTR;
    }
    else
   {
        if(*window != NULL)
        {
            glfwDestroyWindow(*window);
            *window = NULL;
        }
        glfwTerminate();
    }

    return retcode;
}

int create_gl_texture(GLuint *tex, GLuint w, GLuint h)
{
    int retcode = GL_INIT_SUCCESS;

    if(tex == NULL)
    {
        retcode = GL_INIT_NULL_PTR;
    }
    else
    {
        glGenTextures(1, tex);
        glBindTexture(GL_TEXTURE_2D, *tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, 0);
    }

    return retcode;
}
