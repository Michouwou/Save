/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:00:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/09 20:48:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEMP_H
# define _TEMP_H

# include <stddef.h>

typedef	struct		s_warrior
{
	char			reg[REG_NUMBER][REG_SIZE];
	short			pc;
	char			carry;
	int				last_live;
}					t_warrior;

typedef	struct		s_buffer
{
	char			**key;
	void			**data;
	size_t			len;
}					t_buffer;

typedef struct		s_vm
{
	int				dump;
	t_buffer		*buffer_mem;
	t_warrior		**warriors;
	char			memory[MEM_SIZE];
}					t_vm;

void				ft_parse_main_args(char **args, int nb_args,
						t_vm **machine);
// Parse les arguments envoyes au main

void				ft_warrior_parser(char *file_name, t_buffer *buffer,
						int nb_champ);
// Parse un fichier .cor

void				ft_help(char *error_message);
// Stop le programme et permet d'afficher une erreur coherente suivi de l'aide

void				ft_get_dump_option(char *dump_arg, t_vm **machine);
// S'occupe de l'option -dump de la machine

int					ft_parse_match(char *regex_string, char *main_string);
// Renvoie 1 si la regex match la main_string, 0 sinon

void				ft_check_machine_state(t_vm **machine);
// Etabli un bilan de l'etat de la machine a un instant t, interromp l'execution
// du programme si une erreur irreparable est rencontree

void				ft_read_file(char *file_name, char **resource);
// Lit un fichier entier et le stock dans resource (tableau de lignes)

void				ft_header_check(char **resource, int *line);
// Verifie le header d'un .cor, quitte le programme si invalide

int					ft_begins_with_label(char *line);
// Renvoie 1 si la ligne *line commence par un label, 0 sinon

void				ft_label_check(char *line, t_buffer **buffer);
// Check la validite d'un label, peut quitter le programme

void		ft_check_label_instruction(char **resource, int *line);
// Verifie qu'une instruction se trouve bien apres un label sur la meme ligne
// ou sur la ligne suivante, peut quitter le programme

char				*ft_contains_instruction(char *line);
// Renvoie 1 si *line contient une instruction, 0 sinon

void				ft_instruction_validity(char *current_line);
// Verifie que l'instruction est valide, peut quitter le programme

void				ft_check_arg_number(char *current_instruction);
// Check le nombre d'arguments d'une instruction, peut quitter le programme

void				ft_check_arg_type(char *current_instruction);
// Check le type des arguments d'une instruction, peut quitter le programme

void				ft_main_compiler(t_buffer **buffer, char **current_line);
// Fonction principale du processus de compilation d'une line de pseudo-assembleur

int					ft_is_label(char *word);


void				ft_to_mem_addr(char *label, t_buffer **buffer);


int					ft_is_instruction(char *word);


void				ft_bufferize(t_buffer **buffer, char *info, char *type);


char				*ft_get_opcode(char *word);


char				*ft_build_ocp(char **word);


int					ft_is_param(char *word);


int					ft_is_index(char *word);


int					ft_addr_is_label(char *word);


void				ft_get_buffer_addr(t_buffer **buffer, char *word);


void				ft_apply_mod(t_buffer **buffer);


int					ft_is_register(char *word);


void				ft_check_regindex(char *word);


char				*ft_to_bytecode(char *word);


void				ft_dump_buffer_memory(t_buffer **buffer);


t_buffer			*ft_new_buffer();


char				**ft_explode_asm_line(char *line);

#endif
