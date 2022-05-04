/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** free_info_file
*/

#include "my_ls.h"

void free_info_file(info_file_t *file)
{
    for (int i = 0; file[i].name != NULL; i++) {
        free(file[i].permissions);
        free(file[i].date);
        free(file[i].name);
        free(file[i].owner);
        free(file[i].group);
        free(file[i].path);
    }
    free(file);
}
