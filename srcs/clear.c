#include "../includes/ft_ls.h"



void free_struct(t_content *content){
	int i = 0;
	int j;

	if (!content)
		return ;
	while (content[i].files){
		j = 0;
		while (content[i].files[j]) {
			free(content[i].files[j]);
			j++;
		}
		free(content[i].files);
		j = 0;
		if (content[i].owner) {
			while (content[i].owner[j]) {
				free(content[i].owner[j]);
				j++;
			}
			free(content[i].owner);
		}
		j = 0;
		if (content[i].group) {
			while (content[i].group[j]) {
				free(content[i].group[j]);
				j++;
			}
			free(content[i].group);
		}
		j = 0;
		if (content[i].updated_at) {
			while (content[i].updated_at[j]) {
				free(content[i].updated_at[j]);
				j++;
			}
			free(content[i].updated_at);
		}
		j = 0;
		if (content[i].size) {

			while (content[i].size[j]) {
				free(content[i].size[j]);
				j++;
			}
		}
		free(content[i].size);
		free(content[i].timestamps);
		free(content[i].is_dir);
		i++;
	}
	free(content);
}
