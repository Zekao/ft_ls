/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:54:42 by emaugale          #+#    #+#             */
/*   Updated: 2024/03/16 20:46:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int count_files(char *path) {
  DIR *dir;
  struct dirent *entry;
  int count;

  count = 0;
  dir = opendir(path);
  if (!dir) {
    return 0;
  }
  while ((entry = readdir(dir))) {
    count++;
  }
  closedir(dir);
  return count;
}

int execute(char *path, t_content *content) {
  DIR *dir;
  struct dirent *entry;
  int i;
  int size;

  size = count_files(path);
  content->files = malloc(sizeof(char *) * size + 1);
  if (!content->files)
    return 1;
  content->files[size] = NULL;
  content->is_dir = malloc(sizeof(int) * size);
  if (!content->is_dir) {
    free(content->files);
    return 1;
  }
  ft_memset(content->is_dir, false, size);
  dir = opendir(path);
  if (!dir) {
    printf("PATH: %s\n", path);
    return perror("ft_ls"), free(content->files), 1;
  }
  i = 0;
  while ((entry = readdir(dir))) {
    content->files[i] = ft_strdup(entry->d_name);
    if (!content->files[i]) {
      free_struct(content);
      return 1;
    }
    if (entry->d_type == DT_DIR) {
      content->is_dir[i] = true;
    }
    i++;
  }
  closedir(dir);
  return 0;
}
