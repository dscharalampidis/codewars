#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
	accum(const char *source)
{
	int		l_src;
	int		l_dst;
	char	*dst;
	int		i;
	int		j;
	int		multiplier;
	int		flag;

	l_src = strlen(source) + 1;
	l_dst = 0;
	while (--l_src)
	{
		l_dst += l_src;
	}
	l_dst += strlen(source) - 1;
	dst = malloc(sizeof(char) * l_dst);
	i = 0;
	j = 0;
	while (source[i])
	{
		if ((source[i] >= 65 && source[i] <= 90)
			|| (source[i] >= 97 && source[i] <= 122))
		{
			multiplier = i + 2;
			flag = 1;
			while (--multiplier)
			{
				if (source[i] >= 97 && source[i] <= 122 && flag == 1)
				{
					dst[j] = source[i] - 32;
					j++;
				}
				else if (source[i] >= 65 && source[i] <= 90 && flag == 0)
				{
					dst[j] = source[i] + 32;
					j++;
				}
				else
				{
					dst[j] = source[i];
					j++;
				}
				flag = 0;
			}
			dst[j] = 45;
			j++;
		}
		i++;
		dst[l_dst] = 0;
	}
	return (dst);
}

int
	main(void)
{
	char	s[] = "ZpglnRxqenU";
	char	*d;

	d = accum(s);
	printf("%s\n", d);
	free(d);
	return (0);
}
