/*
 * main de ft_memset
 * #include <stdio.h>

int main(void)
{
    int     i = 0;
    char    a[] = {"abcdefghijkl"};
    size_t  len = 2;

    while (i < 8)
    {
        printf("%c", a[i++]);
    }
    printf("%c\n", 'A');
    ft_memset(a, 49, len);
    return (0);
}
*/

/* memmove
#include    <stdio.h>

int main(void)
{
    char        dst[] = {"abcdef"};
    const char  src[] = {"ghijkl"};
    size_t      len = 2;

    ft_memmove(dst, src, len);
    printf("%s \n", dst);
    return (0);
}
*/

/* strlcpy
 *#include <stdio.h>
int main(void)
{
    size_t          dstsize = 3;
    char            dst[] = "abcdef";
    const char      src[] = "ghijkl";

    ft_strlcpy(dst, src, dstsize);
    printf("%zu\n", dstsize);
    printf("%s\n", dst);
    return (0);
}
 *
	strlcat

int main(void)
{
    char        dst[] = "abcdef";
    const char  src[] = "ghijkl";
    size_t      dstsize = 3;
    ft_strlcat(dst, src, dstsize);
    printf("%zu\n", dstsize);
    printf("%s\n", dst);
    return (0);
}

	toupper

	int main(void)
{
    int c = 66;
    c = ft_toupper(c);
    printf("%c\n", c);
}

    strchr

#include <string.h>
#include <stdio.h>

int main(void)
{
    const char str[] = "bbbbbbbbbbbbbalol";
    printf("%s\n", ft_strchr(str, 'a'));
}

	strncmp
int main(void)
{
    int n = 5;
    const char  *s1 = "abcdef";
    const char  *s2 = "abcdgf";
    printf("%i\n", ft_strncmp(s1, s2, n));
    printf("%i\n", strncmp(s1, s2, n));
}

	strnstr

	int main(void)
{
    char    haystack[] = "fghabcdefghijkl";
    char    needle[] = "fghi";
    size_t  len = 20;
    printf("%s\n", ft_strnstr(haystack, needle, len));
}

*/
