# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/19 12:13:09 by ageels        #+#    #+#                  #
#    Updated: 2023/04/19 12:17:51 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =  My_First_Class_in_Orthodox_Canonical_Form

FLAGS = -I. -Wall -Wextra -Werror -std=c++98

SRC = main.cpp\
	Fixed.cpp\
	
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ_DIR)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re