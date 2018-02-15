/**************************************************
 *                  Galen Helfter
 *               ghelfter@gmail.com
 *                     config.h
 **************************************************/

#ifndef _CONFIG_H_
#define _CONFIG_H_

#define CONFIG_SUCCESS    0
#define CONFIG_NULL_PTR   1
#define CONFIG_FOPEN_FAIL 2
#define CONFIG_BAD_ALLOC  3

int config_file_init(const char *filepath);
int config_file_cleanup();

int config_print_error(FILE *fd, int errorcode);

#endif /* _CONFIG_H_ */
