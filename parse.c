#include "wolf.h"
#include "fcntl.h"
#include <stdlib.h>

int		count_word(const char *s, char c)
{
	int nb;
	int	i;
	int check;

	i = 0;
	check = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && check)
			check = !check;
		else if (s[i] != c && !check)
		{
			nb++;
			check = !check;
		}
		i++;
	}
	return (nb);
}

void	split_map(t_env *e, char *map)
{
	int		i;
	int		j;
	char	**split;
	char	**new;

	i = 0;
	j = 0;
	split = ft_strsplit(map, '\n');
	e->world_map = (int**)malloc(sizeof(int*) * e->line);
	while (split[i])
	{
		j = 0;
		e->world_map[i] = (int*)malloc(sizeof(int) * count_word(split[i], ' '));
		if (e->col < count_word(split[i], ' '))
			e->col = count_word(split[i], ' ');
		new = ft_strsplit(split[i], ' ');
		while (new[j])
		{
			e->world_map[i][j] = ft_atoi(new[j]);
			j++;
		}
		i++;
	}
}

void	parse_map(t_env *e)
{
	int		fd;
	char	*line;
	char	*map;

	line = NULL;
	map = ft_strnew(0);
	fd = open(e->filename, O_RDONLY);
	//if fd < 1 go ft_exit
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strjoin(map, ft_strjoin(line, "\n"));
		free(line);
		e->line++;
	}
	close(fd);
	split_map(e, map);
}
