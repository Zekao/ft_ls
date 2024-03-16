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

void print_options(t_options opts) {
  printf("LIST: %d\n", opts.flags[LIST]);
  printf("ALL: %d\n", opts.flags[ALL]);
  printf("RECURSIVE: %d\n", opts.flags[RECURSIVE]);
  printf("REVERSE: %d\n", opts.flags[REVERSE]);
  printf("TIME: %d\n", opts.flags[TIME]);
}

int main(int argc, char **argv, char **env) {

  t_options options;
  (void)argc, (void)env;
  parse_options(&options, argv + 1);
  print_options(options);
}
