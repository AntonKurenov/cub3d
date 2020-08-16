/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:09:50 by elovegoo          #+#    #+#             */
/*   Updated: 2020/07/20 15:02:08 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 20

void	*ft_memmove(void *dest, const void *src, size_t n);
char	*str_join(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
void	del_str(char **str);
int		error_handler(char *str, char **line);

#endif
