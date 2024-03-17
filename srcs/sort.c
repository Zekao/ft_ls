#include "../includes/ft_ls.h"

static void ft_swap(void *a, void *b, size_t size) {
  unsigned char *p = a;
  unsigned char *q = b;
  unsigned char tmp;

  for (size_t i = 0; i < size; ++i) {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
}

static void swap_content(t_content *content, int i, int j, int k) {
  ft_swap(&content[i].is_dir[j], &content[i].is_dir[k], sizeof(bool));
  ft_swap(&content[i].owner[j], &content[i].owner[k], sizeof(char *));
  ft_swap(&content[i].group[j], &content[i].group[k], sizeof(char *));
  ft_swap(&content[i].updated_at[j], &content[i].updated_at[k], sizeof(char *));
  ft_swap(&content[i].size[j], &content[i].size[k], sizeof(char *));
  ft_swap(&content[i].files[j], &content[i].files[k], sizeof(char *));
  ft_swap(&content[i].timestamps[j], &content[i].timestamps[k], sizeof(time_t));
}

void sort_content(t_content *content) {
  int i, j;

  i = 0;
  if (!content[i].files)
    return;
  while (content[i].files) {
    j = 0;
    while (content[i].files[j]) {
      int k = j + 1;
      while (content[i].files[k]) {
        if (ft_strcmp(content[i].files[j], content[i].files[k]) > 0) {
          swap_content(content, i, j, k);
        }
        k++;
      }
      j++;
    }
    i++;
  }
}

void reverse_sort_content(t_content *content) {
  int i = 0;
  int j = 0;

  if (!content[i].files)
    return;
  while (content[i].files) {
    j = 0;
    while (content[i].files[j]) {
      int k = j + 1;
      while (content[i].files[k]) {
        swap_content(content, i, j, k);
        k++;
      }
      j++;
    }
    i++;
  }
}

void sort_timestamps(t_content *content) {
  int i, j;

  i = 0;
  while (content[i].files) {
    j = 0;
    while (content[i].files[j]) {
      int k = j + 1;
      while (content[i].files[k]) {
        if (content[i].timestamps[j] < content[i].timestamps[k]) {
          swap_content(content, i, j, k);
        }
        k++;
      }
      j++;
    }
    i++;
  }
}
