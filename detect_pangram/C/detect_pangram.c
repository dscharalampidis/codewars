#include <stdbool.h>
#include <stdio.h>

bool
	is_pangram(const char *str_in)
{
	char	a[] ="abcdefghijklmnopqrstuvwxyz";
	char	A[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (a[i])
	{
		j = 0;
		while (str_in[j])
		{
			if (str_in[j] == a[i] || str_in[j] == A[i])
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (k == 26)
		return (true);
	else
		return (false);
}

int
	main(void)
{
	char s[] = "Cwm fjord bank glyphs vext quiz";

	if (is_pangram(s))
	{
		printf("This string is a pangram.");
	}
	else 
	{
		printf("This string is not a pangram.");
	}
	return (0);
}
