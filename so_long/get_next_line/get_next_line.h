/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:27:33 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/09 02:35:58 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_strndup_(char *s, size_t n);
size_t	ft_strlen_(char *s);
char	*ft_strjoin_(char *s1, char *s2);
char	*ft_strncpy_(char *dest, char *src, size_t n);
char	*ft_strchr_(char *s, int c);
char	*ft_strdup_(char *s);
char	*get_next_line(int fd);

#endif
