/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/03/31 17:57:46 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int parse_options(t_options *options, char **params) {
  ft_memset(options, false, sizeof(t_options));
  int ret;
  ret = 0;

  for (int i = 0, j; params[i] && params[i][0] == '-'; i++) {
    for (j = 1; params[i][j]; j++) {
      switch (params[i][j]) {
      case 'l':
        options->flags[LIST] = true;
        continue;
      case 'R':
        options->flags[RECURSIVE] = true;
        continue;
      case 'a':
        options->flags[ALL] = true;
        continue;
      case 'r':
        options->flags[REVERSE] = true;
        continue;
      case 't':
        options->flags[TIME] = true;
        continue;
      default:
        ft_putstr("ft_ls: illegal option -- ");
        ft_putchar(params[i][j]);
        ft_putchar('\n');
        exit(1);  
      }
    }
    if (!params[i + 1])
      return i + 1;
    ret += 1;
  }
  return ret;
}
