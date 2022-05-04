/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** ls_l
*/

#include "my_ls.h"

void display_l(info_file_t *file)
{
    char *path_linked;

    for (int i = 0; file[i].name != NULL; i++) {
        my_printf("%c%s. %d %s %s ", file[i].is_directory,
        file[i].permissions, file[i].hard_link, file[i].owner, file[i].group);
        if (file[i].is_directory == 'c' || file[i].is_directory == 'b') {
            my_printf("%d, %d %s %s", file[i].maj, file[i].min, file[i].date,
            file[i].name);
        } else {
            my_printf("%d %s %s", file[i].size, file[i].date, file[i].name);
        }
        if (file[i].is_directory == 'l') {
            path_linked = malloc(file[i].size + 1);
            path_linked[file[i].size] = '\0';
            readlink(file[i].path, path_linked, file[i].size);
            my_printf(" -> %s\n", path_linked);
            free(path_linked);
        } else
            my_printf("\n");
    }
}

info_file_t *my_ls_l(char *filename, sort_func *sort, sort_func *rev,
info_func *get_info)
{
    DIR *dir = opendir(filename);
    struct dirent *dir_tmp;
    info_file_t *file = malloc(sizeof(info_file_t) * 1000);
    int total_block = 0;

    if (dir == NULL && get_info != &get_info_folder)
        exit(84);
    else if (get_info != &get_info_folder)
        dir_tmp = readdir(dir);
    total_block = (*get_info)(dir_tmp, dir, file, filename);
    (*sort)(file);
    (*rev)(file);
    if (total_block != -1)
        my_printf("total %d\n", total_block);
    display_l(file);
    closedir(dir);
    return (file);
}
