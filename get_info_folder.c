/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** ls_d
*/

#include "my_ls.h"

int get_info_folder(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path)
{
    struct stat st;

    if (stat(path, &st) == -1)
        exit(84);
    file[0].is_directory = if_directory(st);
    file[0].hard_link = st.st_nlink;
    file[0].permissions = get_permissions(st);
    file[0].owner = my_strdup(getpwuid(st.st_uid)->pw_name);
    file[0].group = my_strdup(getgrgid(st.st_gid)->gr_name);
    file[0].time = st.st_mtime;
    file[0].date = get_time(file[0].time);
    file[0].size = st.st_size;
    file[0].name = my_strdup(path);
    file[0].path = my_strdup(path);
    file[0].maj = st.st_rdev >> 8 & 255;
    file[0].min = st.st_rdev & 255;
    file[1].name = NULL;
    return (-1);
}
