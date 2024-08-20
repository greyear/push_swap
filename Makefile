# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 16:12:25 by azinchen          #+#    #+#              #
#    Updated: 2024/08/20 20:20:19 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME 				= 	push_swap

# Directories
LIBFT				= 	./libft/libft.a
INCLUDE				= 	include/
SRC_DIR 			= 	src/
OBJ_DIR 			= 	obj/

# Compiler and compilation flags
CC 					= 	cc
CFLAGS 				= 	-g -Wall -Wextra -Werror -I
RM					= 	rm -f
AR					= 	ar rcs

# Source Files
OPERATIONS_DIR		=	$(SRC_DIR)operations/push.c \
										$(SRC_DIR)operations/swap.c \
										$(SRC_DIR)operations/rotate.c \
										$(SRC_DIR)operations/rev_rotate.c
						
LOGICS_DIR			=	$(SRC_DIR)logics/push_swap.c \
										$(SRC_DIR)logics/turk.c \
										$(SRC_DIR)logics/moving_costs.c \
										$(SRC_DIR)logics/sort_three.c \
										$(SRC_DIR)logics/creating_stack.c \
										$(SRC_DIR)logics/stack_fields.c \
										$(SRC_DIR)logics/stack_elem.c \
										$(SRC_DIR)logics/stack_utils.c \
										$(SRC_DIR)logics/error_utils.c

SRC 				=	$(OPERATIONS_DIR) $(LOGICS_DIR)

# Object files         
OBJ 				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

#Build rules

all: 				$(NAME)

$(LIBFT):
					@make -C ./libft


$(NAME): 			$(OBJ) $(LIBFT)
							@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
							@mkdir -p $(@D)
							@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re
