/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/03/16 19:31:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_putchar(char c) { write(1, &c, 1); }

void ft_putstr(char *str) { write(1, str, ft_strlen(str)); }

void ft_putendl(char *str) {
  write(1, str, ft_strlen(str));
  ft_putchar('\n');
}

int ft_strlen(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

void *ft_memset(void *str, int c, size_t n) {
  size_t i;
  unsigned char *tempstr;

  tempstr = (unsigned char *)str;
  i = 0;
  while (n) {
    tempstr[i] = c;
    i++;
    n--;
  }
  return (str);
}
