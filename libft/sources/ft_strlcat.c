#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	result_len;

	dst_len = ft_strlen(dst);
	result_len = FT_MIN(dstsize, dst_len) + ft_strlen(src);
	if (dstsize > dst_len)
	{
		dst += dst_len;
		dstsize -= dst_len;
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (result_len);
}
