/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/17 18:08:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// computes the length of the string s
// @param s input string
// @return number of characters that precede the terminating NULL character
size_t	ft_strlen(const char *s);

// @brief Allocates with malloc and returns a substring from the string ’s’. \
// @brief The substring begins at index ’start’ and is of maximum size ’len’.
// @param s The string from which to create the substring.
// @param start The start index of the substring in the string ’s’.
// @param len The maximum length of the substring.
// @return The substring. \
// @return NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
// @param s1 The prefix string.
// @param s2 The suffix string.
// @return The new string. \
// @return NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2);

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
// @param s1 The string to be trimmed.
// @param set The reference set of characters to trim.
// @return The trimmed string. \
// @return NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

// @brief Allocates (with malloc(3)) and returns an array \
// @brief of strings obtained by splitting ’s’ using the \
// @brief character ’c’ as a delimiter.  The array must end \
// @brief with a NULL pointer.
// @param s The string to be split. \
// @param c The delimiter character.
// @return The array of new strings resulting from the split. \
// @return NULL if the allocation fails.
char	**ft_split(char const *s, char c);

// @brief Allocates (with malloc(3)) and returns a string \
// @brief representing the integer received as an argument. \
// @param n the integer to convert.
// @return The string representing the integer.\
// @return NULL if the allocation fails.
char	*ft_itoa(int n);

#endif