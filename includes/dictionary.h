/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:57:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:30:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "libft_internal.h"

typedef t_uint64			(*t_hash_func)(void *key, size_t dict_size);

typedef struct s_dict_int	t_dictionary_int;
typedef struct s_dict_el	t_dict_el;
typedef struct s_list_dict	t_list_dict;

struct s_dict_el
{
	void	*key;
	void	*val;
};

struct s_list_dict
{
	t_dict_el	*data;
	t_list_dict	*next;
};

struct s_dict_int
{
	size_t		size;
	t_hash_func	hash_func;
	void		(*free_key)(void *);
	void		*(*dup_key)(void *);
	void		(*free_val)(void *);
	void		*(*dup_val)(void *);
	t_list_dict	**vals;
};

#endif // DICTIONARY_H