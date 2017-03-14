# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 11:39:32 by grass-kw          #+#    #+#              #
#    Updated: 2017/03/14 18:15:13 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= ft_select

DEBUG 			= no
HEADER			= ft_select
### DIRECTORIES ###
DIRSRC			:= resources/src
DIROBJ			:= resources/obj
DIRINC			:= resources/includes
DIRFT			:= resources/libft
DIRCLST			:= resources/clst

DIRMAIN 		:= $(DIRSRC)/main
DIRCOREUTILS 	:= $(DIRSRC)/coreutils
DIRPARSER 		:= $(DIRSRC)/parser
DIREVENT 		:= $(DIRSRC)/event
DIRSELECTION 	:= $(DIRSRC)/selection
DIRSIGNAL 		:= $(DIRSRC)/signal
DIRTERMINAL 	:= $(DIRSRC)/terminal
DIRCAPACITY 	:= $(DIRSRC)/capacity

### FILES ###
HEAD	:= $(DIRINC)/$(HEADER).h

include 	$(DIRMAIN)/sources.mk
include 	$(DIRCOREUTILS)/sources.mk
include 	$(DIRPARSER)/sources.mk
include 	$(DIREVENT)/sources.mk
include 	$(DIRSELECTION)/sources.mk
include		$(DIRSIGNAL)/sources.mk
include 	$(DIRTERMINAL)/sources.mk
include 	$(DIRCAPACITY)/sources.mk

POBJ	:= $(addprefix $(DIROBJ)/, $(OBJ))


### COMPILATION VARIABLES ###
CC	:= gcc
ifeq ($(DEBUG),yes)
	C_FLAG	:= -Wall -Werror -Wextra -g -ltermcap
else
	C_FLAG	:= -Wall -Werror -Wextra -ltermcap
endif

C_INC	:= -I $(DIRINC)  -I $(DIRFT)/includes -I $(DIRCLST)/includes
L_FLAG	:= -L $(DIRFT) -lft -L $(DIRCLST) -lclst


COMPIL	= $(CC) -o $@ -c $< $(C_INC)
LINK	= @$(CC) -o $@ $^ $(L_FLAG) $(C_FLAG)

### RULES ###
.PHONY: all clean fclean re lldb
.SILENT:

all: $(NAME)

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	make -C $(DIRFT)
	make -C $(DIRCLST)
	$(LINK)
### LIBS ###

### MICS ###
clean:
	@rm -rf $(DIROBJ)

fclean: clean
	@rm -f $(NAME)
	make -C $(DIRFT) fclean
	make -C $(DIRCLST) fclean

re: fclean all

lldb: $(NAME)
	lldb $(NAME)
