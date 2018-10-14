#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2018/07/21 11:07:03 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lmatvien.filler
NAME1 = libft_mini.a
NAME_V = battlefield.vs

FLAGS  += -Wall -Werror -Wextra
FILLER_HEADER += ./includes/
FT_LIB_MINI_HDR += ./srcs/libft_mini/

CFILES = 	fl_main.c \
			fl_checking_figure_in_the_point.c \
			fl_figure.c \
			fl_mforces.c \
			fl_reader.c \
			fl_target.c \
			fl_tops.c \
			fl_writer.c \

LIBFILE =   ft_atoi_base.c \
			ft_itoa.c \
			ft_strnew.c \
			ft_pow.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_putnbr_fd.c \
			ft_putstr_error.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_strnlen.c \
	 		ft_strdup.c \
			ft_strjoin.c \
			ft_strstr.c \
			ft_memset.c \
			ft_strncat.c \
			ft_strcat.c \
			get_next_line.c \
			ft_strsplit.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_swap.c \

V_FILE = 	tw_main.c \
			tw_parsing.c \
			tw_parsing_map.c \
			tw_mem_control.c \
			tw_render_map.c \
			tw_control_ls.c \

FILLER_SRC = $(addprefix ./srcs/, $(CFILES))
FT_LIB_SRC = $(addprefix ./srcs/libft_mini/, $(LIBFILE))
V_FILE_SRC = $(addprefix ./theater_of_war/srcs/, $(V_FILE))

OBJ1    = $(FT_LIB_SRC:.c=.o)
OBJMAIN = $(FILLER_SRC:.c=.o)
OBJ_V   = $(V_FILE_SRC:.c=.o)
OBJ_FILE_V = $(V_FILE:.c=.o)
.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ1): %.o: %.c 
	@gcc -c $(FLAGS) $< -o $@
$(OBJMAIN): %.o: %.c
	@gcc -c $(FLAGS) -I ./includes $< -o $@
$(OBJ_V): %.o: %.c 
	@gcc -c $(FLAGS) -I $(HOME)/.brew/Cellar/sdl2/2.0.8/include/SDL2/ -I $(HOME)/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2/ $< -o $@

$(NAME): $(OBJ1) $(OBJMAIN) $(OBJ_V)
	@ar rcs ./srcs/libft_mini/$(NAME1) $(OBJ1)
	@gcc $(OBJMAIN) -I ../includes ./srcs/libft_mini/libft_mini.a -o $(NAME)
	@cd ./theater_of_war/srcs && \
	gcc $(OBJ_FILE_V) ../../srcs/libft_mini/libft_mini.a -I $(HOME)/.brew/Cellar/sdl2/2.0.8/include/SDL2/ -I $(HOME)/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2/ -L $(HOME)/.brew/Cellar/sdl2/2.0.8/lib/ -lSDL2 -L $(HOME)/.brew/Cellar/sdl2_ttf/2.0.14/lib/ -lSDL2_ttf -o $(NAME_V)
	@echo "\033[35;1m>>>Created FT_LIB_MINI\033[0m"
	@echo "\033[31;1m>>>Complete\033[0m"
clean:
	@/bin/rm -f $(OBJ1)
	@/bin/rm -f $(OBJMAIN)
	@/bin/rm -f $(OBJ_V)
	@echo "\033[35;1m>>>Removed OBJ Files\033[0m"
	
fclean: clean
	@/bin/rm -rf ./srcs/libft_mini/$(NAME1)
	@/bin/rm -rf ./lmatvien.filler
	@/bin/rm -rf ./theater_of_war/srcs/battlefield.vs
	@echo "\033[35;1m>>>Removed executed files\033[0m"

re: fclean all