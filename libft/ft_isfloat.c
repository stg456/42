#include "libft.h"

static bool	ft_isfloat2(const char *str)
{
	int	pointcount;

	pointcount = 0;
	if (str++ == '.')
	{
		pointcount++;
		if (pointcount > 1)
			return (false);
	}
	return ;
}

bool	ft_isfloat(const char *str)
{
	int	pointcount;
	int	signcount;
	int	i;

	pointcount = 0;
	i = 0;
	signcount = 0;
	while (str[i] != '\0')
	{
		ft_isfloat2(str);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+' && i != 0)
			return (false);
		else if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (false);
		else if ((str[i] == '-' || str[i] == '+') && i == 0)
			signcount++;
		i++;
	}
	if (str[ft_strlen(str) - 1] == '.')
		return (false);
	return (true);
}

int main() {
    const char *chaine1 = "3.14";    // Valide
    const char *chaine2 = "-2.5";    // Valide
    const char *chaine3 = "+10.0";   // Valide
    const char *chaine4 = "2..5";    // Invalide
    const char *chaine5 = "abc";     // Invalide

    if (estFloatValide(chaine1)) {
        printf("%s est un nombre à virgule flottante valide.\n", chaine1);
    } else {
        printf("%s n'est pas un nombre à virgule flottante valide.\n", chaine1);
    }

    if (estFloatValide(chaine2)) {
        printf("%s est un nombre à virgule flottante valide.\n", chaine2);
    } else {
        printf("%s n'est pas un nombre à virgule flottante valide.\n", chaine2);
    }

    if (estFloatValide(chaine3)) {
        printf("%s est un nombre à virgule flottante valide.\n", chaine3);
    } else {
        printf("%s n'est pas un nombre à virgule flottante valide.\n", chaine3);
    }

    if (estFloatValide(chaine4)) {
        printf("%s est un nombre à virgule flottante valide.\n", chaine4);
    } else {
        printf("%s n'est pas un nombre à virgule flottante valide.\n", chaine4);
    }

    if (estFloatValide(chaine5)) {
        printf("%s est un nombre à virgule flottante valide.\n", chaine5);
    } else {
        printf("%s n'est pas un nombre à virgule flottante valide.\n", chaine5);
    }

    return 0;
}
