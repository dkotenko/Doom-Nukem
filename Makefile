# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clala <clala@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 16:58:46 by clala             #+#    #+#              #
#    Updated: 2020/12/20 20:45:15 by clala            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALL_C = main.c \
		object3d.c \
		projection.c \
		camera.c \
		matrix4.c \
		matrix_functions.c \
		set_sdl.c \
		init_bonus.c \
		init.c \
		error.c \
		sdl.c \
		render_text.c \
		draw.c \
		load_textures.c \
		t_vec4.c \
		t_vec3.c \
		t_sector.c \
		t_polygon.c \
		vertices.c

SRCDIR = ./src
OBJDIR = ./objs
ALL_OBJ = $(ALL_C:%.c=%.o)
OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

NAME = doom_nukem

INCLUDES = ./includes/wolf3d.h \
			./includes/const.h \
			./includes/colors.h \
			./includes/errors.h \
			./includes/vec2.h


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
COMP_LIB = make -C $(LIBFT_DIR)
CC = gcc
FLAGS = -Wall -Wextra -Werror -ffast-math -O3 -funroll-loops

SDL_INCS =	-F./frameworks \
			-I./frameworks/SDL2.framework/Headers \
			-I./frameworks/SDL2_image.framework/Headers \
			-I./frameworks/SDL2_mixer.framework/Headers \
			-I./frameworks/SDL2_ttf.framework/Headers
			 
FRAMEWORKS  = -F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 \
				-framework SDL2_ttf \
				-framework SDL2_image \
				-framework SDL2_mixer


all: $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $@ $(SDL_INCS) $(FRAMEWORKS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	$(CC) $(FLAGS) -I./includes -I.$(LIBFT_DIR)/includes $(SDL_INCS)  -c $< -o $@ 

$(OBJDIR):
	/bin/mkdir -p $(OBJDIR)

$(LIBFT): lib

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf $(OBJDIR)
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
