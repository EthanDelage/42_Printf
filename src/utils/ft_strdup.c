#include <stdlib.h>
#include <errno.h>

static size_t   ft_strlen(const char *str);

char    *ft_strdup(const char *str)
{
    char            *new;
    size_t          index;
    const size_t    len = ft_strlen(str) + 1;

    new = (char *) malloc(sizeof(char) * len);
    if (errno)
        return (NULL);
    index = 0;
    while (index < len)
    {
        new[index] = str[index];
        index++;
    }
    return (new);
}

static size_t   ft_strlen(const char *str)
{
    size_t  count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}