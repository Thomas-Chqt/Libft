/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/19 21:31:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// @brief Test if `c` is uppercase or lowercase
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isalpha(int c);

// @brief Test if `c` is a number (0-9)
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isdigit(int c);

// @brief tests for which ft_isalpha or ft_isdigit is true
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isalnum(int c);

// @brief tests for an ASCII character
// @param c character to test
// @return zero if the tests false and non-zero if the tests true.
int		ft_isascii(int c);

// computes the length of the string s
// @param s input string
// @return number of characters that precede the terminating NULL character
size_t	ft_strlen(const char *s);

// @brief Allocates with malloc and returns a substring from the string ’s’. 
// @brief The substring begins at index ’start’ and is of maximum size ’len’.
// @param s The string from which to create the substring.
// @param start The start index of the substring in the string ’s’.
// @param len The maximum length of the substring.
// @return The substring. 
// @return NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
// @param s1 The prefix string.
// @param s2 The suffix string.
// @return The new string.
// @return NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2);

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
// @param s1 The string to be trimmed.
// @param set The reference set of characters to trim.
// @return The trimmed string.
// @return NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

// @brief Allocates (with malloc(3)) and returns an array
// @brief of strings obtained by splitting ’s’ using the
// @brief character ’c’ as a delimiter.  The array must end
// @brief with a NULL pointer.
// @param s The string to be split.
// @param c The delimiter character.
// @return The array of new strings resulting from the split.
// @return NULL if the allocation fails.
char	**ft_split(char const *s, char c);

// @brief Allocates (with malloc(3)) and returns a string
// @brief representing the integer received as an argument. 
// @param n the integer to convert.
// @return The string representing the integer.
// @return NULL if the allocation fails.
char	*ft_itoa(int n);

// @brief Applies the function ’f’ to each character of the 
// @brief string ’s’, and passing its index as first argument 
// @brief to create a new string (with malloc(3)) resulting 
// @brief from successive applications of ’f’.
// @param s The string on which to iterate. 
// @param f The function to apply to each character.
// @return The string created from the successive applications 
// @return of ’f’. 
// @return Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// @brief Applies the function ’f’ on each character of
// @brief the string passed as argument, passing its index
// @brief as first argument.  Each character is passed by
// @brief address to ’f’ to be modified if necessary.
// @param s The string on which to iterate.
// @param f The function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// @brief Outputs the character ’c’ to the given file
// @brief descriptor.
// @param c The character to output.
// @param fd The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd);

// @brief Outputs the string ’s’ to the given file
// @brief descriptor.
// @param s The string to output.
// @param fd The file descriptor on which to write.
void	ft_putstr_fd(char *s, int fd);

// @brief Outputs the string ’s’ to the given file descriptor
// @brief followed by a newline.
// @param s The string to output.
// @param fd The file descriptor on which to write.
void	ft_putendl_fd(char *s, int fd);

// @brief Outputs the integer ’n’ to the given file
// @brief descriptor.
// @param n The integer to output.
// @param fd The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd);

#endif