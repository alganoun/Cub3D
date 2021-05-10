NAME		=	Cub3D

HEAD 		=	./includes/*.h

INC			=	-I./includes/

C			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INFO		=	echo "Cub3d is compiling..." &&

#LIB_LINUX	=	./mlx_linux/libmlx.a -lm -lbsd -lX11 -lXext

LIB_MAC	=	-Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

LIB			=	$(LIB_MAC)

SRCS		=	./cub3d.c \
				./Utils/utils.c \
				./Utils/utils2.c \
				./Utils/utils3.c \
				./Utils/atoi_utils.c \
				./Utils/free_utils.c \
				./Utils/free_utils2.c \
				./Utils/get_next_line.c \
				./Utils/get_next_line_utils.c \
				./Errors/double_params.c \
				./Errors/map_checker.c \
				./Errors/map_checker2.c \
				./Errors/write_errors.c \
				./Errors/write_errors2.c \
				./Errors/check_path.c \
				./Initialisation/errors_init.c \
				./Initialisation/game_init.c \
				./Initialisation/image_init.c \
				./Initialisation/keys_init.c \
				./Initialisation/map_init.c \
				./Initialisation/overall_init.c \
				./Initialisation/params_init.c \
				./Initialisation/player_init.c \
				./Initialisation/ray_init.c \
				./Initialisation/sprite_init.c \
				./Initialisation/window_init.c \
				./Map/map.c \
				./Params/params.c \
				./Params/params_ccol.c \
				./Params/params_fcol.c \
				./Params/params_res.c \
				./Params/params_text.c \
				./Raycasting/bmp.c \
				./Raycasting/drawing_process.c \
				./Raycasting/drawing_process2.c \
				./Raycasting/raycasting_calculation.c \
				./Raycasting/raycasting_calculation2.c \
				./Raycasting/raycasting_keys.c \
				./Raycasting/raycasting_move.c \
				./Raycasting/raycasting_player.c \
				./Raycasting/raycasting_rotate.c \
				./Raycasting/raycasting_setup.c \
				./Raycasting/raycasting_utils.c \
				./Raycasting/raycasting.c \
				./Raycasting/raycasting2.c \
				./Raycasting/sprite_process.c

OBJ			=	$(SRCS:.c=.o)

all: 	$(NAME)

$(OBJ): $(HEAD)

$(NAME): $(OBJ)
	@echo "\033[0;35mThe MinilibX is compiling" \
		&& sleep 1  && echo "...\033[0m"
	@cd mlx && make
	@echo "\033[0;32mThe MinilibX compilation was succesfull.\033[0m"
	@cd ..
	@echo "\033[0;35mCub3D is compiling" \
		&& sleep 1  && echo "...\033[0m" \
		&& make process

process: $(OBJ)
	@$(CC) $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[0;32mCub3D compilation was succesfull.\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@echo "\033[0;31mCub3D object files deletion complete\033[0m"

test:
	valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=no ./$(NAME) _map_files/simple.cub

fclean: clean
	@rm -f $(NAME)
	@rm -f "screenshot.bmp"
	@cd mlx && make clean && cd ..
	@echo "\033[0;31mMinilibX objects files deletion complete\033[0m"

re:
	@make clean
	@make process

.PHONY: all clean fclean re
