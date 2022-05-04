/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** ls_upper_r
*/

#include "my_ls.h"

char *create_path(char *path, char *filename)
{
    char *desc = malloc(my_strlen(path) + my_strlen(filename) + 2);

    desc[0] = '\0';
    my_strcat(desc, path);
    my_strcat(desc, "/");
    my_strcat(desc, filename);
    desc[my_strlen(path) + my_strlen(filename) + 1] = '\0';
    return (desc);
}

void my_ls_upper_r(char *path, sort_func *sort, sort_func *rev, ls_func *ls)
{
    DIR *dir = opendir(path);
    info_file_t *file_info;
    char *path_tmp;

    if (dir == NULL)
        return;
    closedir(dir);
    my_printf("%s:\n", path);
    file_info = (*ls)(path, sort, rev, &get_info_file);
    for (int i = 0; file_info[i].name != NULL; i++) {
        if (file_info[i].is_directory == 'd') {
            path_tmp = create_path(path, file_info[i].name);
            my_putchar('\n');
            my_ls_upper_r(path_tmp, sort, rev, ls);
            free(path_tmp);
        }
    }
    free_info_file(file_info);
}
