/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/04/02 08:19:15 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <string.h>

int main(int argc, char **argv) {
  t_options options;
  int count = parse_options(&options, argv + 1) + 1;
  argv += count;
  argc -= count;
  if (argv[0] == NULL || argc == 0) {
    argc = 1;
    argv[0] = ".";
  }
  ft_ls(argc, argv, options);
}

int ft_ls(int argc, char **argv, t_options options) {
  t_content *contents;

  contents = calloc(sizeof(t_content), argc + 1);
  if (!contents)
    return 1;
  int j = 0;
  for (int i = 0; i < argc; i++) {
    if (execute(argv[i], &contents[j]) == 1)
      continue;
    j++;
  }
  handle_output(argc, argv, contents, options);
  free_struct(contents);
  return 0;
}
