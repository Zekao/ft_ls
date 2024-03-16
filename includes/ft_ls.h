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
#include <string.h>
#include <unistd.h>

enum Options { ALL, LIST, TIME, RECURSIVE, REVERSE };

typedef struct s_options {
  bool flags[5];
} t_options;

typedef struct s_content {
  char **files;
  bool *is_dir;
} t_content;

int parse_options(t_options *options, char **params);

void print_error(char *message);
void print_usage(char *message);
void *ft_memset(void *str, int c, size_t n);

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putendl(char *str);
int ft_strlen(const char *str);
void ft_putendt(char *str);
int execute(char *path, t_content *content);
char *ft_strdup(char *str);
void free_struct(t_content *content);
int ft_ls(int argc, char **argv, t_options options);
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
int ft_ls_recursive(char **argv, t_options options);
