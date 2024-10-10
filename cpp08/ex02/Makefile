# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 22:50:29 by nicolas           #+#    #+#              #
#    Updated: 2024/07/24 21:47:46 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=mystack
SRCS= main.cpp
GREEN=\033[1;32m
BLUE=\033[1;34m
RES=\033[0m

${NAME}: ${SRCS}
	@echo "${BLUE}Compiling...${RES}"
	@c++ -Werror -Wall -Wextra -g -std=c++98 ${SRCS} -o ${NAME}
	@echo "${GREEN}Compiled successfully!${RES}"

fclean:
	@rm -fr ${NAME}

re: fclean ${NAME}

.PHONY: re fclean