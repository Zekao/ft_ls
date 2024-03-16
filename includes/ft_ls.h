/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:49 by emaugale          #+#    #+#             */
/*   Updated: 2024/03/16 19:31:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Options { ALL, LIST, TIME, RECURSIVE, REVERSE };

typedef struct s_options {
  bool flags[5];
} t_options;

void parse_options(t_options *options, char **argv);

/* Utils functions */
void print_error(char *message);
void print_usage(char *message);
void *ft_memset(void *str, int c, size_t n);

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putendl(char *str);
int ft_strlen(char *str);
