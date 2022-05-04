/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** get_info
*/

#include "my_ls.h"

char *get_permissions(struct stat st)
{
    char *permissions = malloc(sizeof(char) * 10);
    int p[3] = {st.st_mode >> 6 & 7, st.st_mode >> 3 & 7, st.st_mode & 7};

    for (int i = 0; i < 10; i++)
        permissions[i] = '-';
    permissions[9] = '\0';
    for (int i = 0; i < 3; i++) {
        if (p[i] & 4)
            permissions[i * 3] = 'r';
        if (p[i] & 2)
            permissions[i * 3 + 1] = 'w';
        if (p[i] & 1)
            permissions[i * 3 + 2] = 'x';
    }
    if (st.st_mode & __S_ISVTX) {
        permissions[8] = (permissions[8] == 'x') ? 't' : 'T';
    }
    return (permissions);
}

char if_directory(struct stat st)
{
    if ((st.st_mode & __S_IFMT) == __S_IFDIR)
        return ('d');
    if ((st.st_mode & __S_IFMT) == __S_IFLNK)
        return ('l');
    if ((st.st_mode & __S_IFMT) == __S_IFBLK)
        return ('b');
    if ((st.st_mode & __S_IFMT) == __S_IFIFO)
        return ('p');
    if ((st.st_mode & __S_IFMT) == __S_IFCHR)
        return ('c');
    return ('-');
}

char *get_time(time_t time_sec)
{
    char *calendar_time = ctime(&time_sec) + 4;
    char *output = malloc(sizeof(char) * 13);

    my_strncpy(output, calendar_time, 13);
    output[12] = '\0';
    return (output);
}

void put_info_in_array(struct dirent *dir_tmp, info_file_t *file,
struct stat st, int i)
{
    file[i].is_directory = if_directory(st);
    file[i].hard_link = st.st_nlink;
    file[i].permissions = get_permissions(st);
    file[i].owner = my_strdup(getpwuid(st.st_uid)->pw_name);
    file[i].group = my_strdup(getgrgid(st.st_gid)->gr_name);
    file[i].time = st.st_mtime;
    file[i].date = get_time(file[i].time);
    file[i].size = st.st_size;
    file[i].name = my_strdup(dir_tmp->d_name);
    file[i].maj = st.st_rdev >> 8 & 255;
    file[i].min = st.st_rdev & 255;
}

int get_info_file(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path)
{
    struct stat st;
    int i = 0;
    int nb_block = 0;
    char *path_tmp;

    for (; dir_tmp != NULL; dir_tmp = readdir(dir)) {
        path_tmp = create_path(path, dir_tmp->d_name);
        if (dir_tmp->d_name[0] != '.' && lstat(path_tmp, &st) != -1) {
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
