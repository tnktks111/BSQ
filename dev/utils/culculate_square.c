#include "dev.h"

int	calculate_square(int height, int width)
{
	int	small;

	small = ft_min(height, width);
	return (small * small);
}
