/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *               vertex_shader.vert 
 **************************************************/
#version 130

/* Inputs */
in vec3 vp;
in vec3 inorm;
in vec2 iuv;

/* Matrix uniforms */
uniform mat4 proj_mat;
uniform mat4 view_mat;

out vec4 position;
out vec3 normal;
out vec2 uv;

/* Vertex shader main program */
void main(void)
{
    normal = vec3(proj_mat * view_mat * vec4(inorm, 1.0));
    uv = iuv;
    /* Return */
    position = proj_mat * view_mat * vec4(vp, 1.0);
    gl_Position = proj_mat * view_mat * vec4(vp, 1.0);
}
