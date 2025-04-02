/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:38:15 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:13:18 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEV_H
# define DEV_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_board_info
{
	long long	**grid;
	long long	r;
	long long	c;
	long long	cur_max;
	long long	coordinates[3];
}	t_g_info;

typedef struct s_basic_info
{
	char		**lines;
	char		empty;
	char		obstacle;
	char		full;
	long long	r;
	long long	c;
}	t_basic_info;

typedef struct s_node
{
	long long		data;
	struct s_node	*next;
}	t_node;

# define BUF_SIZE 2

ssize_t		file_size(char *file);
char		*file_read(char *file);

t_node		*create_node(long long data);
int			insert_bf_head(t_node **head, long long data);
int			delete_head(t_node **head);
int			is_empty(t_node **stack);
void		push(t_node **stack, long long data);
long long	pop(t_node **stack);

long long	ft_max(long long s1, long long s2);
long long	ft_min(long long s1, long long s2);
void		ft_putstr(char *str);
long long	ft_strlen(char *str);
long long	calculate_square(long long height, long long width);
void		ft_putstr_error(char *str);
char		*ft_strjoin(char *s1, char *s2, long long len2);
char		**ft_split(char *str, long long r, long long c);
void		ft_putstrarr(char **arr);
long long	ft_atoi(char *str, long long *num);
void		ft_multiassign(long long *t, long long a, long long b, long long c);
long long	get_left_index(t_node **stack);
long long	get_width(long long i, t_node **stack);
int			ft_is_numeric(char *str);
char		*get_sub(char *str, int left, int right);

int			validation(char *str, t_basic_info *info);
int			is_print(char c);
int			check_head(char *str);
long long	check_size(char *str);
void		set_info(t_basic_info *info, char e, char o, char f);
int			check_r(char *r, char empty, char obstacle, long long size);
void		fill_board_r(long long *dest, char *src, long long len, char empty);
void		compute_histograms(t_g_info *info);
void		free_board(long long **board, long long rs);
void		print_board(long long **board, long long r, long long c);
void		solve_hist_map(t_g_info *board_info);
void		solve_hist_r(long long *h, long long s, t_g_info *i, long long r);
void		convert(t_basic_info *basic_info, t_g_info *board_info);
int			parse(char *file_path);
int			parse_input(char *input);
char		*resize_buffer(char *input, long long *buf_size, long long i);
int			handle_buffer_resize(char **buf, long long *buf_s, long long i);
int			get_input(char **input);
t_g_info	*parse_map(char **lines, t_basic_info *basic_info);

#endif
