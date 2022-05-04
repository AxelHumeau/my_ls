/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** get_info_a
*/

#include "my_ls.h"

int get_info_file_a(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path)
{
    struct stat st;
    int i = 0;
    int nb_block = 0;
    char *path_tmp;

    for (; dir_tmp != NULL; dir_tmp = readdir(dir)) {
        path_tmp = create_path(path, dir_tmp->d_name);
        if (lstat(path_tmp, &st) != -1) {
            put_info_in_array(dir_tmp, file, st, i);
            nb_block += st.st_blocks / 2;
            file[i].path = my_strdup(path_tmp);
            i++;
        }
        free(path_tmp);
    }
    file[i].name = NULL;
    return (nb_block);
}
