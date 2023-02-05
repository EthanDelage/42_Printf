int is_no_flags(t_param *token)
{
    return (token->hashtag == false
        && token->zero == false
        && token->left_align == false
        && token->space == false
        && token->plus == false
        && token->precision == false);
}