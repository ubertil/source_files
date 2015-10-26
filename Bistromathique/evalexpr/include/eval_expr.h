/*
** eval_expr.h for eval_expr in /home/uberti_l/rendu/Piscine_C_evalexpr/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct 21 09:32:35 2015 louis-emile uberti-ares
** Last update Mon Oct 26 16:51:08 2015 louis-emile uberti-ares
*/

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

#define	OPEN_PAR '('
#define	CLOSE_PAR ')'
#define	ERROR_MSG "Error : Wrong syntax\n"
#define	USAGE_MSG "Usage : ./calc base operators size_read\n"
#define	PAR_MSG "Error : Wrong syntax\nPlease check your parenthesis twice\n"
#define	R_MSG "Error : read_size too big. Please retry using the right size\n"
#define	OPERATORS_MSG "Please check your operators twice\n"
#define	EOS '\0'

struct		s_number
{
  char		*n1;
  char		*n2;
  unsigned long	idx;
};

struct		s_op
{
  char		sign;
  int		(*fct)(char **);
};

struct		s_parenthesis
{
  int		OP_PAR;
  int		CP_PAR;
};

typedef struct s_number t_number;
typedef struct s_op t_op;
typedef struct s_parenthesis t_par;

t_op signs[] =
  {
    // ('+', &summands, 0),
    // ('-', &summands, 0),
    // ('*', &factors, 1),
    // ('/', &factors, 1),
    // ('%', &factors, 1),
  };

/*
** is_expr_valid.c
*/

char	*get_expr(unsigned int size);
int	par_checker(char *expr, char *to_use, char *base, char *operators);
char	my_get_to_use(char *expr, char *to_use, char *base, char *operators);
int	check_ops(char *expr, char *to_use, char *base, char *operators);
int	check_expr_twice(char *expr, char *to_use, char *base, char *operators);

#endif /* !EVAL_EXPR_H */
