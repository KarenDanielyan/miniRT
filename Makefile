NAME		=	miniRT

INCLUDE		=	./include

LIBFT		=	lib/libft/libft.a

PRINTF		=	lib/printf/libftprintf.a

PLATFORM	=	$(shell uname -s)

BUILD		=	build

SRC			=	src

SUBDIRS		=	core scanner math events utils job debug shaders

DEP			=	$(patsubst %.h, $(INCLUDE)/%.h, \
				defines.h miniRT.h scanner.h \
				vec3.h color.h utils.h \
				ray.h ui.h camera.h matrix4.h) \
				Makefile

SRCS		=	$(patsubst %.c, $(SRC)/core/%.c, \
				main.c ray.c ui.c camera.c) \
				$(patsubst %.c, $(SRC)/utils/%.c, \
				create_image.c new_image.c float_cmp.c \
				fill_image.c get_time.c \
				progress_bar.c) \
				$(patsubst %.c, $(SRC)/scanner/%.c, \
				check_extension.c) \
				$(patsubst %.c, $(SRC)/math/%.c, \
				vec3_constructors.c vec3_operations.c \
				vec3_get.c vec3_set.c vec3_utils.c \
				matrix4.c) \
				$(patsubst %.c, $(SRC)/events/%.c, \
				on_destroy.c on_keypress.c) \
				$(patsubst %.c, $(SRC)/job/%.c, \
				tasks.c put_render.c \
				listener.c update.c worker.c) \
				$(patsubst %.c, $(SRC)/debug/%.c, \
				print_messages.c) \
				$(patsubst %.c, $(SRC)/shaders/%.c, \
				ray_shader.c)

OBJS		=	$(foreach dir, $(SUBDIRS), \
				$(patsubst $(SRC)/$(dir)/%.c, $(BUILD)/%.o, \
				$(filter $(SRC)/$(dir)/%.c, $(SRCS))))

# Compilation Options

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-fPIC -g -Wall -Wextra -Werror -std=gnu99 -D BUFFER_SIZE=100000 -fsanitize=address

INVOKE		=	libft printf mlx

IFLAGS		=	-Iinclude -Ilib/libft -Ilib/printf/include

LFLAGS		=	-Llib/libft -lft -Llib/printf -lftprintf -lm

ifeq ($(PLATFORM),Linux)
	MLX		=	lib/mlx_linux
	IFLAGS	+=	-I/usr/include -I$(MLX)
	LFLAGS	+=	-L$(MLX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(PLATFORM), Darwin)
	MLX		=	lib/mlx_mac
	IFLAGS	+=	-I$(MLX)
	LFLAGS	+=	-L$(MLX) -lmlx -framework OpenGL -framework AppKit
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

printf:
			@$(MAKE) $(MAKECMDGOALS) -C lib/printf

wait_msg:
			@echo "${BLUE}Please wait for $(NAME) to compile.${RESET}"

clean:		$(INVOKE)
			@echo "${CYAN}Cleaning Build...${RESET}"
			@$(RM) $(BUILD)
			@echo "${GREEN}Done.${RESET}"

fclean:		libft printf
			@echo "${CYAN}Cleaning Everyting...${RESET}"
			@$(MAKE) clean -C $(MLX)
			@$(RM) $(BUILD)
			@$(RM) $(NAME) $(NAME)_old
			@echo "${GREEN}Done.${RESET}"

mlx:
				@$(MAKE) $(MAKECMDGOALS) -C $(MLX)

re:			fclean all

.PHONY:		all clean fclean re libft printf mlx wait_msg
