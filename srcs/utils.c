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

void ft_putendt(char *str) {
  write(1, str, ft_strlen(str));
  ft_putchar('\t');
}

int ft_strlen(const char *str) {
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

char *ft_strdup(char *str) {
  char *dest;
  int i;

  i = ft_strlen(str);
  dest = malloc(sizeof(char) * (i + 1));
  if (dest == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    dest[i] = str[i];
  dest[i] = '\0';
  return (dest);
}

int ft_strcmp(char *s1, char *s2) {
  int i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

int ft_strncmp(char *s1, char *s2, size_t n) {
  size_t i;
  int diff;

  i = 0;
  while ((s1[i] || s2[i]) && i < n) {
    if (s1[i] != s2[i]) {
      diff = (unsigned char)s1[i] - (unsigned char)s2[i];
      return (diff);
    }
    i++;
  }
  return (0);
}

char *ft_strjoin(char const *s1, char const *s2) {
  int i;
  int j;
  int size;
  char *newstr;

  j = 0;
  i = 0;
  if (!s1 || !s2)
    return (NULL);
  size = ft_strlen(s1) + ft_strlen(s2);
  newstr = malloc(sizeof(char) * (size + 1));
  if (!newstr)
    return (NULL);
  while (s1[i]) {
    newstr[i] = s1[i];
    i++;
  }
  while (s2[j]) {
    newstr[i + j] = s2[j];
    j++;
  }
  newstr[i + j] = '\0';
  return (newstr);
}
