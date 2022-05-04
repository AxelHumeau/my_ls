/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** my_ls
*/

#pragma once

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include "my.h"

typedef struct option_presence_s {
    int l;
    int r;
    int R;
    int d;
    int t;
    int a;
} option_presence_t;

typedef struct info_file_s {
    char is_directory;
    char *permissions;
    int hard_link;
    char *owner;
    char *group;
    int time;
    char *date;
    int size;
    int maj;
    int min;
    char *name;
    char *path;
} info_file_t;

typedef void (sort_func)(info_file_t *);
typedef int (info_func)(struct dirent *, DIR *, info_file_t *, char *);
typedef info_file_t *(ls_func)(char *, sort_func *, sort_func *, info_func *);

void find_options(char *str, option_presence_t *options);
info_file_t *my_ls_standard(char *filename, sort_func *sort, sort_func *rev,
info_func *get_info);
info_file_t *my_ls_l(char *filename, sort_func *sort, sort_func *rev,
info_func *get_info);
void my_ls_upper_r(char *path, sort_func *sort, sort_func *rev, ls_func *ls);
void time_sort(info_file_t *file);
void alpha_sort(info_file_t *file);
void reverse_sort(info_file_t *file);
int get_info_file(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path);
char *get_time(time_t time_sec);
char if_directory(struct stat st);
char *get_permissions(struct stat st);
void free_info_file(info_file_t *file);
void do_nothing(info_file_t *file);
char *get_time(time_t time_sec);
char if_directory(struct stat st);
char *get_permissions(struct stat st);
int get_info_folder(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path);
int get_info_file_a(struct dirent *dir_tmp, DIR *dir, info_file_t *file,
char *path);
void display_l(info_file_t *file);
void put_info_in_array(struct dirent *dir_tmp, info_file_t *file,
struct stat st, int i);
char *create_path(char *path, char *filename);
