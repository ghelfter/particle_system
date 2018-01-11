/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                   particle.cl
 **************************************************/

/* Kernel */
__kernel void integrate(const global float *in_particles,
                        global float *out_particles,
                        unsigned int *active_particles)
{
    const size_t i = get_global_id(0);
    unsigned int temp_active = *active_particles;

    /* Edit the active particle count */
    *active_particles = temp_active;
}
