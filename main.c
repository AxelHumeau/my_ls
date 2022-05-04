/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** main
*/

#include "my_ls.h"

void do_nothing(info_file_t *file)
{
    return;
}

void call_ls(option_presence_t options, char *filepath)
{
    sort_func *sort = (options.t) ? &time_sort : &alpha_sort;
    sort_func *rev = (options.r) ? &reverse_sort : &do_nothing;
    info_func *info = (options.d && options.R == 0) ?
    &get_info_folder : &get_info_file;
    int index_func = (options.l) ? 1 : 0;
    ls_func *LS_FUNC[2] = {&my_ls_standard, &my_ls_l};

    if (options.a && !options.d) {
        info = &get_info_file_a;
    }
    if (options.R) {
        my_ls_upper_r(filepath, sort, rev, LS_FUNC[index_func]);
        return;
    }
    free_info_file(LS_FUNC[index_func](filepath, sort, rev, info));
}

int main(int argc, char **argv)
{
    option_presence_t options = {0, 0, 0, 0, 0, 0};
    int i = 1;

    if (argc == 1) {
        my_ls_standard(".", &alpha_sort, &do_nothing, &get_info_file);
        return (0);
    }
    for (; i < argc && argv[i][0] == '-'; i++)
        find_options(argv[i], &options);
    if (i == argc) {
        call_ls(options, ".");
    } else {
        for (; i < argc; i++)
            call_ls(options, argv[i]);
    }
    return (0);
}
