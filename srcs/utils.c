/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/04/02 09:25:18 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_putchar(char c) { write(1, &c, 1); }

void ft_putstr(char *str) {
  if (!str) {
    return;
  }
  write(1, str, ft_strlen(str));
}

void ft_putendt(char *str) {
  if (!str)
    return;
  write(1, str, ft_strlen(str));
  ft_putchar('\t');
}

void ft_putendl(char *str) {
  write(1, str, ft_strlen(str));
  ft_putchar('\n');
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

static int ft_count_size(int nbr) {
  int size;

  size = 1;
  if (nbr == 0)
    return (2);
  if (nbr < 0) {
    nbr = nbr * -1;
    size++;
  }
  while (nbr) {
    nbr = nbr / 10;
    size++;
  }
  return (size);
}

char *ft_itoa(int nbr) {
  long int nb;
  int size;
  char *str;

  nb = nbr;
  size = ft_count_size(nb);
  str = malloc(sizeof(char) * size);
  if (!str)
    return (NULL);
  if (nb < 0) {
    str[0] = '-';
    nb = nb * -1;
  }
  if (nb == 0)
    str[0] = '0';
  size--;
  str[size] = '\0';
  while (nb) {
    str[size - 1] = nb % 10 + '0';
    nb = nb / 10;
    size--;
  }
  return (str);
}

void ft_error(char *str) {
  write(2, "Error: ", 7);
  write(2, str, ft_strlen(str));
  write(2, "\n", 1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, (count * size));
	return (str);
}