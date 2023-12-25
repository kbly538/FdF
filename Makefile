NAME 			=	fdf
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror


LIBDIR			= 	./lib/

LIBFT_PATH		=	libft/
LIBFT			= 	$(LIBFT_PATH)libft.a

MLX_PATH		=	minilibx_macos/
MLX				= 	$(MLX_PATH)libmlx.a

FT_PRINTF_PATH	=	$(LIBFT_PATH)ft_printf/
FT_PRINTF		= 	$(FT_PRINTF_PATH)libftprintf.a


OPENGL			=	-framework OpenGL -framework AppKit


SRC 			=	main.c \
					hooks.c \
					color_utils.c \
					drawing_utils.c \
					map_load.c map_utils.c map_data_utils.c \
					error.c \
					generic_utils.c string_utils.c math_utils.c \
					camera.c \
					info_screen.c draw_info.c map_info.c \
					update.c \
					transformations.c \
					mouse_controls.c keyboard_controls.c \
					projections.c \
					controllers_info.c \
					coloring.c palette.c

OBJ				= 	$(SRC:%.c=%.o)

SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS			=	-I$(LIBFT_PATH) -I$(FT_PRINTF_PATH) -I$(MLX_PATH)


all				:	$(OBJ_PATH) $(NAME)


$(OBJ_PATH)%.o	: 	$(SRC_PATH)%.c
					$(CC) $(CFLAGS) -c $< -o $@ $(INCS) -g3
					

$(OBJ_PATH)	:	
					mkdir $(OBJ_PATH)	

$(NAME)			:	$(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) 
					$(CC) $(CFLAGS) $(OBJS) -o $@  $(LIBFT) $(FT_PRINTF) $(MLX) $(OPENGL) $(INCS) -g3


$(LIBFT)		:	
					@make -C $(LIBFT_PATH)

$(MLX)			:	
					@make -C $(MLX_PATH) all

$(FT_PRINTF)	:	
					@make -C $(FT_PRINTF_PATH) all

clean			:	
					rm -f $(OBJS)
					
					

fclean			:	clean
					rm -f $(NAME)
					@$(MAKE) -C $(LIBFT_PATH) fclean
					@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	

re				:	fclean all

refdf		:   clean
					rm -rf $(OBJ_PATH)
					rm $(NAME)
					@$(MAKE) all


.PHONY: all clean fclean re refdf