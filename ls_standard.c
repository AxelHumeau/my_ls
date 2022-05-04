/*
** EPITECH PROJECT, 2021
** ls_standard
** File description:
** ls_stadard
*/

#include "my_ls.h"

info_file_t *my_ls_standard(char *filename, sort_func *sort, sort_func *rev,
info_func *get_info)
{
    DIR *dir = opendir(filename);
    struct dirent *dir_tmp;
    info_file_t *file = malloc(sizeof(info_file_t) * 1000);

    if (dir == NULL && get_info != &get_info_folder)
        exit(84);
    else if (get_info != &get_info_folder)
        dir_tmp = readdir(dir);
    (*get_info)(dir_tmp, dir, file, filename);
    (*sort)(file);
    (*rev)(file);
    for (int i = 0; file[i].name != NULL; i++) {
        my_printf("%s\n", file[i].name);
    }
    closedir(dir);
    return (file);
}
