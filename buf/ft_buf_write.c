/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 22:39:32 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_buf_write(t_buf dst, t_buf src, size_t offset)
{
	size_t	new_dst_size;

	if (dst.size == INVALID_SIZE || src.size == INVALID_SIZE)
		return (NULL);
	if ((size_t)dst.size < offset + (size_t)src.size)
	{
		new_dst_size = ft_max_size(dst.size * 2, offset + src.size);
		dst.buf = ft_realloc(dst.buf, dst.size, new_dst_size);
		if (!dst.buf)
		{
			dst.size = INVALID_SIZE;
			return (NULL);
		}
		dst.size = new_dst_size;
	}
	ft_memcpy(dst.buf + offset, src.buf, src.size);
	return (dst.buf + offset);
}
