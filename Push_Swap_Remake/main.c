
int main(int argc, char **argv)
{
    char    *options;
    int     i;
    t_stack *alpha;
    t_stack *beta;
    t_sol   *solution;
    
    options = ft_strnew(5);
    alpha = NULL;
    beta = NULL;
    i = 0;
    if (argc < 2)
        ft_stop();
    else
    {
        options = ft_extract_options(argv);
        while (i < argc - ft_strlen(options))
            ft_add_number(alpha, ft_atoi(argv[i]), 'a');
        solution = ft_core(alpha, beta, options);
    }
    ft_display(solution, options);
}