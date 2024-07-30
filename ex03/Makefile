# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 18:56:10 by svydrina          #+#    #+#              #
#    Updated: 2024/07/30 13:52:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm

SRCS = AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp Intern.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

HEADERS = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp \
ShrubberyCreationForm.hpp Intern.hpp

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) ShrubberyCreationForm_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean all
