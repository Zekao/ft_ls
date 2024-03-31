#include "../includes/ft_ls.h"

void display_list(char *owner, char *group, char *size, char *updated_at,
                         char *file) {
  ft_putendt(owner);
  ft_putendt(group);
  ft_putendt(size);
  ft_putendt(updated_at);
  ft_putendl(file);
}

int print_ls(int argc, char **argv, t_content *contents, t_options options) {
  char *tmp;
  for (int i = 0; i < argc; i++) {
    if (argc > 1) {
      ft_putstr(argv[i]);
      ft_putstr(":\n");
    }

    if (contents[i].files == NULL)
      return 1;
    for (int j = 0; contents[i].files[j]; j++) {
      if (options.flags[ALL] == false && contents[i].files[j][0] == '.')
        continue;
      ft_putendt(contents[i].files[j]);
    }
    ft_putchar('\n');
    if (options.flags[RECURSIVE] == true) {
      for (int j = 0; contents[i].files[j]; j++) {
        if (contents[i].is_dir[j] == 1) {
          if (ft_strcmp(contents[i].files[j], ".") != 0 &&
              ft_strcmp(contents[i].files[j], "..") != 0) {
            char *new_argv[2];
            tmp = ft_strjoin(argv[i], "/");
            if (!tmp)
              return 1;
            new_argv[0] = ft_strjoin(tmp, contents[i].files[j]);
            if (!new_argv[0])
              return 1;
            new_argv[1] = NULL;
            free(tmp);
            ft_ls_recursive(new_argv, options);
            free(new_argv[0]);
          }
        }
      }
    }
  }
  return 0;
}

void print_list(t_content *contents, t_options options) {
  int i, j;

  i = 0, j = 0;
  while (contents[i].files) {
    while (contents[i].files[j]) {
      if (options.flags[ALL] == false && contents[i].files[j][0] == '.') {
        j++;
        continue;
      }
      display_list(contents[i].owner[j], contents[i].group[j],
                   contents[i].size[j], contents[i].updated_at[j],
                   contents[i].files[j]); 
      j++;
    }
    j = 0;
    i++;
  }
}

void handle_output(int argc, char **argv, t_content *contents,
                   t_options options) {
  if (options.flags[TIME] == true) {
    sort_timestamps(contents);
  }
  if (options.flags[REVERSE] == true) {
    reverse_sort_content(contents);
  }
  if (options.flags[LIST] == true && options.flags[RECURSIVE] == false) {
    print_list(contents, options);
  } else {
    if (print_ls( argc, argv, contents, options)) {
      ;
    }
  }
}
