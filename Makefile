 # **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 18:18:58 by svoort         #+#    #+#                 #
#    Updated: 2019/03/15 14:23:37 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	alum1

FUN		=	main.c print_stuff.c get_next_line.c check_input.c ft_error.c \
			game.c random.c
			
FUNDIR	=	./

GFLG	=	gcc -Wall -Wextra -Werror -c

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

HD		=	$(addprefix -I, .)

OBJDIR	=	./obj/

OBJS	=	$(FUN:.c=.o)

OBJ		=	$(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME):  $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft -lft
	@echo $(NAME) "ready"

$(OBJDIR)%.o: $(FUNDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(GFLG) $(HD) -o $@ $<

clean:
	make -C libft clean
	@rm -rf $(OBJDIR)
	@echo "Objects deleted"

fclean: clean
	make -C libft fclean
	@rm -f $(NAME)
	@echo $(NAME) "deleted"

re: fclean all
