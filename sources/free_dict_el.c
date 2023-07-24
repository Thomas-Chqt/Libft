/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict_el.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:39:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 17:40:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	free_dict_el(t_dict_el *el, void (*free_key)(void *), void (*free_val)(void *))
{
	free_key(el->key);
	free_val(el->val);
	free(el);
}
