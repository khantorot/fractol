#include "libft.h"

intmax_t	ft_pow_int(intmax_t num, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (num * (ft_pow_int(num, power - 1)));
}
