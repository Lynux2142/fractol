# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2020/07/30 15:04:53 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS			= $(shell uname)
NAME			= fractol

SRCS1			= fractol.c
SRCS1			+= mouse_funct.c
SRCS1			+= keyboard_funct.c
SRCS1			+= fract1.c fract2.c
SRCS1			+= fract3.c
SRCS1			+= fract4.c
SRCS1			+= pixel.c
SRCS1			+= annex_funct.c
SRCS1			+= set_color.c
SRCS1			+= set_string.c
SRCS1			+= create_fdf.c
SRCS1			+= put_infos.c

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS1))
OBJS			= $(addprefix $(OBJS_DIR), $(SRCS1:.c=.o))

SRCS_DIR		= ./srcs/
OBJS_DIR		= ./objs/
LIBFT_DIR		= ./libft/
INCLUDES_DIR	= ./includes/

LIBFT			= $(LIBFT_DIR)libft.a
MINILIBX		= $(MLX_DIR)libmlx.a
HEADER			= $(INCLUDES_DIR)fractol.h

FLAGS			= -Wall -Wextra -Werror -O2 -g
CC				= clang

ifeq ($(OPE_SYS), Linux)
	MLX_DIR		= ./minilibx_x11/
	INCLUDES	= $(addprefix -I, $(INCLUDES_DIR) $(LIBFT_DIR) $(MLX_DIR) /usr/include)
	FRAMEWORK	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lpthread
else
	MLX_DIR		= ./minilibx/
	INCLUDES	= $(addprefix -I, $(INCLUDES_DIR) $(LIBFT_DIR) $(MLX_DIR))
	FRAMEWORK	= -framework OpenGL -framework Appkit -lpthread
endif

##################
##    COLORS    ##
##################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_CLEAR		= "\033[2K"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all launch clean fclean re norme title
.SILENT:

all: launch

launch: title
	$(MAKE) $(LIBFT)
	$(MAKE) $(MINILIBX)
	echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)$(NAME)$(_END)
	$(MAKE) $(NAME)
	echo $(_GREEN)"\nDone."$(_END)$(_SHOW_CURS)

$(OBJS_DIR):
	mkdir $@

$(LIBFT): FORCE
	$(MAKE) -sC libft
	echo

$(MINILIBX): FORCE
	$(MAKE) -sC $(MLX_DIR) 2>/dev/null

FORCE:

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(FRAMEWORK) $(MINILIBX) -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	printf $<

clean:
	$(MAKE) -sC libft clean
	$(MAKE) -sC $(MLX_DIR) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -sC libft fclean
	$(RM) $(NAME)

re:
	$(MAKE) -s fclean
	$(MAKE) -s

norme:
	norminette srcs/*.c includes/*.h
	$(MAKE) -C libft norme

title:
	echo $(_RED)
	echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	echo
	echo "       :::::::::: :::::::::      :::      :::::::: ::::::::::: ::::::::  :::   "
	echo "      :+:        :+:    :+:   :+: :+:   :+:    :+:    :+:    :+:    :+: :+:    "
	echo "     +:+        +:+    +:+  +:+   +:+  +:+           +:+    +:+    +:+ +:+     "
	echo "    :#::+::#   +#++:++#:  +#++:++#++: +#+           +#+    +#+    +:+ +#+      "
	echo "   +#+        +#+    +#+ +#+     +#+ +#+           +#+    +#+    +#+ +#+       "
	echo "  #+#        #+#    #+# #+#     #+# #+#    #+#    #+#    #+#    #+# #+#        "
	echo " ###        ###    ### ###     ###  ########     ###     ########  ##########  "
	echo
	echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	printf $(_YELLOW)
	echo "                                                                2018 © lguiller"
	echo $(_END)
