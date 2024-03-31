#include "../includes/ft_ls.h"

void free_struct(t_content *content) {
  int i = 0;
  if (content->files) {
    while (content->files[i]) {
      free(content->files[i]);
      free(content->owner[i]);
      free(content->group[i]);
      free(content->updated_at[i]);
      free(content->size[i]);
      i++;
    }
    free(content->files);
  }
  if (content->is_dir)
    free(content->is_dir);
  if (content->owner)
    free(content->owner);
  if (content->group)
    free(content->group);
  if (content->updated_at)
    free(content->updated_at);
  if (content->size)
    free(content->size);
  if (content->timestamps)
    free(content->timestamps);
  free(content);
}
