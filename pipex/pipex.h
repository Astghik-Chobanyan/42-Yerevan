/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:12:12 by achobany          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:58 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	ft_putstr_fd(char *s, int fd);
int		ft_countword(char *s, char c);
int		ft_wordlen(char *s, char c);
char	**ft_free(char **a);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);
int		path_index(char **envp);
char	*get_path(char **envp, char *cmd);

#endif
