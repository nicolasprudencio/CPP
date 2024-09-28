# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 22:50:29 by nicolas           #+#    #+#              #
#    Updated: 2024/09/21 21:55:43 by nprudenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bureaucrat
SRCS=Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
GREEN=\033[1;32m
BLUE=\033[1;34m
RES=\033[0m

${NAME}: ${SRCS}
	@echo "${BLUE}Compiling...${RES}"
	@c++ -Wall -Wextra -Werror -std=c++98 ${SRCS} -o ${NAME} -g
	@echo "${GREEN}Compiled successfully!${RES}"

fclean:
	@rm -fr ${NAME}

re: fclean ${NAME}

.PHONY: re fclean