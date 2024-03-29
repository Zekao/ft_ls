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

int allocate_memory(char ***ptr, int size, t_content *content, int is_bool) {
  if (is_bool) {
    content->is_dir = malloc(sizeof(int) * size);
    if (content->is_dir == NULL) {
      return free_struct(content), 1;
    }
    for (int i = 0; i < size; i++) {
      content->is_dir[i] = 0;
    }
  } else {
    *ptr = malloc(sizeof(char *) * (size + 1));
    if (*ptr == NULL) {
      return free_struct(content), 1;
    }
    (*ptr)[size] = NULL;
  }
  return 0;
}

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

void fill_content(char *path, t_content *content, int i) {
  struct stat fileStat;
  struct passwd *user;
  struct group *group;
  char *updated_at;

  if (stat(path, &fileStat) < 0) {
    printf("Error: %s\n", path);
    return;
  }

  user = getpwuid(fileStat.st_uid);
  if (user == NULL) {
    exit(EXIT_FAILURE);
  }

  group = getgrgid(fileStat.st_gid);
  if (group == NULL) {
    exit(EXIT_FAILURE);
  }
  updated_at = ctime(&fileStat.st_mtime);
  updated_at[ft_strlen(updated_at) - 1] = '\0';
  content->owner[i] = ft_strdup(user->pw_name);
  content->group[i] = ft_strdup(group->gr_name);
  content->updated_at[i] = ft_strdup(updated_at + 4);
  content->size[i] = ft_itoa(fileStat.st_size);
  content->timestamps[i] = fileStat.st_mtime;
}

int execute(char *path, t_content *content) {
  DIR *dir;
  struct dirent *entry;
  int i;
  int size;

  size = count_files(path);

  allocate_memory(NULL, size, content, 1);
  allocate_memory(&(content->files), size, content, 0);
  allocate_memory(&(content->owner), size, content, 0);
  allocate_memory(&(content->group), size, content, 0);
  allocate_memory(&(content->updated_at), size, content, 0);
  allocate_memory(&(content->size), size, content, 0);
  content->timestamps = malloc(sizeof(long int) * size);
  if (content->timestamps == NULL) {
    return free_struct(content), 1;
  }

  ft_memset(content->is_dir, false, size);
  ft_memset(content->timestamps, 0, size);
  dir = opendir(path);
  if (!dir) {
    return perror("ft_ls"), free_struct(content), 1;
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
    char *tmp = ft_strjoin(path, "/");
    if (!tmp) {
      free_struct(content);
      return 1;
    }
    char *tmp2 = ft_strjoin(tmp, content->files[i]);
    if (!tmp2) {
      free(tmp);
      free_struct(content);
      return 1;
    }
    fill_content(tmp2, content, i);
    free(tmp);
    free(tmp2);
    i++;
  }
  sort_content(content);
  closedir(dir);
  return 0;
}
