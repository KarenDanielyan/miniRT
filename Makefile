NAME		=	miniRT

INCLUDE		=	include

LIBFT		=	lib/libft/libft.a

BITMAP		=	lib/ft_bitmap/libftbitmap.a

PLATFORM	=	$(shell uname -s)

BUILD		=	build

SRC			=	src

SUBDIRS		=	core scanner math events utils job debug shaders

DEP			=	$(patsubst %.h, $(INCLUDE)/%.h, \
				camera.h defines.h material.h \
				matrix.h miniRT.h quaternion.h \
				ray.h scanner.h shapes.h ui.h \
				vec3.h) \
				Makefile \
				$(LIBFT) $(BITMAP)

SRCS		=	$(patsubst %.c, $(SRC)/core/%.c, \
				main.c ray.c ui.c camera.c hit.c hit_2.c \
				hittable.c lights.c shapes.c normals.c \
				material.c normals_from_map.c) \
				$(patsubst %.c, $(SRC)/utils/%.c, \
				create_image.c new_image.c float_cmp.c \
				fill_image.c get_time.c mapping.c \
				progress_bar.c clamp.c darray_cmp.c) \
				$(patsubst %.c, $(SRC)/scanner/%.c, \
				check_file.c scan.c parse_ambient.c \
				parse_light.c parse_camera.c parse_sphere.c \
				parse_utils.c parse_cylinder.c \
				parse_plane.c parse_cone.c parse_utils2.c) \
				$(patsubst %.c, $(SRC)/math/%.c, \
				vec3_constructors.c vec3_operations.c \
				vec3_operations_2.c vec3_get.c \
				vec3_set.c vec3_utils.c \
				vec3_random.c quaternion_operations.c\
				quaternion_constructors.c \
				matrix.c matrix_operations.c \
				uv_compute.c) \
				$(patsubst %.c, $(SRC)/events/%.c, \
				on_destroy.c on_keypress.c) \
				$(patsubst %.c, $(SRC)/job/%.c, \
				tasks.c put_render.c \
				listener.c update.c worker.c) \
				$(patsubst %.c, $(SRC)/shaders/%.c, \
				ray_shader.c skybox_shader.c \
				blinn_phong_shader.c \
				ambient_shader.c linear_to_gamma.c \
				raster_light_shader.c \
				color_shader.c)

OBJS		=	$(foreach dir, $(SUBDIRS), \
				$(patsubst $(SRC)/$(dir)/%.c, $(BUILD)/%.o, \
				$(filter $(SRC)/$(dir)/%.c, $(SRCS))))

# Compilation Options

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=100000 -g -fsanitize=address

INVOKE		=	libft ft_bitmap mlx

IFLAGS		=	-Iinclude -Ilib/libft -Ilib/ft_bitmap

LFLAGS		=	-lm -Llib/ft_bitmap -lftbitmap

ifeq ($(PLATFORM),Linux)
	MLX		=	lib/mlx_linux
	IFLAGS	+=	-I/usr/include -I$(MLX)
	LFLAGS	+=	-L$(MLX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llib/libft -l:libft.a
endif
ifeq ($(PLATFORM), Darwin)
	MLX		=	lib/mlx_mac
	IFLAGS	+=	-I$(MLX)
	LFLAGS	+=	-L$(MLX) -lmlx -framework OpenGL -framework AppKit -Llib/libft -lft

endif

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
CYAN	=	\033[36m
BLUE	=	\033[34m

# Recipies
all:		wait_msg $(INVOKE) $(NAME)

$(BUILD):
			@mkdir -p $(BUILD)

$(BUILD)/%.o:	$(SRC)/%.c $(DEP)
			@echo "${CYAN}Compiling $<.${RESET}"
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o:	$(SRC)/*/%.c $(DEP)
			@echo "${CYAN}Compiling $<.${RESET}"
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME):	$(BUILD) $(OBJS) $(LIBFT) $(PRINTF)
			@cp -f $(NAME) $(NAME)_old 2> /dev/null || :
			@echo "${GREEN}Building $(NAME).${RESET}"
			@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS)
			@echo "${GREEN}Build Successfull.${RESET}"

libft:
			@$(MAKE) $(MAKECMDGOALS) -C lib/libft

ft_bitmap:
			@git submodule update --init --recursive
			@$(MAKE) $(MAKECMDGOALS) -C lib/ft_bitmap

wait_msg:
			@echo "${BLUE}Please wait for $(NAME) to compile.${RESET}"

clean:		$(INVOKE)
			@echo "${CYAN}Cleaning Build...${RESET}"
			@$(RM) $(BUILD)
			@echo "${GREEN}Done.${RESET}"

fclean:		libft ft_bitmap
			@echo "${CYAN}Cleaning Everyting...${RESET}"
			@$(MAKE) clean -C $(MLX)
			@$(RM) $(BUILD)
			@$(RM) $(NAME) $(NAME)_old
			@echo "${GREEN}Done.${RESET}"

mlx:
				@$(MAKE) $(MAKECMDGOALS) -C $(MLX)

re:			fclean all

.PHONY:		all clean fclean re libft ft_bitmap mlx wait_msg
