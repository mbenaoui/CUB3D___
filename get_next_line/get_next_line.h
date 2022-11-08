/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:29:25 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/12/11 12:04:45 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#define BUFFER_SIZE 1
char	*my_ft_strchr(char *s, int c);
char	*my_ft_strjoin(char *s1, char *s2);
size_t	my_ft_strlen( char *s);
char	*get_next_line(int fd);
char	*my_ft_strdup(char *s1);

#endif
