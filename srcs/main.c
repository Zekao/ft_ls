/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/03/16 19:46:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <string.h>

void print_options(t_options opts) {
  printf("LIST: %d\n", opts.flags[LIST]);
  printf("ALL: %d\n", opts.flags[ALL]);
  printf("RECURSIVE: %d\n", opts.flags[RECURSIVE]);
  printf("REVERSE: %d\n", opts.flags[REVERSE]);
  printf("TIME: %d\n", opts.flags[TIME]);
}

int main(int argc, char **argv) {
  t_options options;
  int count = parse_options(&options, argv + 1) + 1;
  // print_options(options);
  argv += count;
  argc -= count;
  if (argv[0] == NULL || argc == 0) {
    argc = 1;
    argv[0] = ".";
  }
  ft_ls(argc, argv, options);
}

int ft_ls(int argc, char **argv, t_options options) {
  char *tmp;
  t_content *contents;

  contents = malloc(sizeof(t_content) * argc);
  if (!contents)
    return 1;
  for (int i = 0; i < argc; i++) {
    if (execute(argv[i], &contents[i]) == 1)
      return 0;
  }
  for (int i = 0; i < argc; i++) {
    if (i != 1) {
      ft_putstr(argv[i]);
      ft_putstr(":\n");
    }

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
            new_argv[1] = NULL;
            free(tmp);
            ft_ls_recursive(new_argv, options);
            free(new_argv[0]);
          }
        }
      }
    }
  }
  free_struct(contents);
  return 0;
}
