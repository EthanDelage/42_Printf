#include "printf.h"

int conversion_char(t_param *token, unsigned char c)
{
    char    *conv;

    conv = (char *) malloc(sizeof(char) * 2);
    if (errno)
    {
        conv = NULL;
        return (FAILURE);
    }
    conv[0] = c;
    conv[1] = '\0';
    token->value = conv;
    return (SUCCESS);
}