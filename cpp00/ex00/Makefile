# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 22:50:29 by nicolas           #+#    #+#              #
#    Updated: 2024/07/22 23:00:08 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone
SRCS=megaphone.cpp
GREEN=\033[1;32m
BLUE=\033[1;34m
RES=\033[0m

${NAME}: ${SRCS}
	@echo "${BLUE}Compiling...${RES}"
	@c++ -Wall -Wextra -Werror -std=c++98 ${SRCS} -o $@
	@echo "${GREEN}Compiled successfully!${RES}"

fclean:
	@rm -fr ${NAME}

re: fclean ${NAME}

.PHONY: re fclean