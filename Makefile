NAME		=	miniRT

INCLUDE		=	./include

LIBFT		=	lib/libft/libft.a

PRINTF		=	lib/printf/libftprintf.a

PLATFORM	=	$(shell uname -s)

BUILD		=	build

SRC			=	src

SUBDIRS		=	scanner

DEP			=	$(patsubst %.h, $(INCLUDE)/%.h, \
				) \
				Makefile

SRCS		=	main.c \
				$(patsubst %.c, $(SRC)/scanner/%.c, \
				check_extension.c scan.c)

OBJS		=	$(foreach dir, $(SUBDIRS), \
				$(patsubst $(SRC)/$(dir)/%.c, $(BUILD)/%.o, \
				$(filter $(SRC)/$(dir)/%.c, $(SRCS)))) \
				$(patsubst %.c, $(BUILD)/%.o, main.c)

# Compilation Options

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-g -Wall -Wextra -Werror -D BUFFER_SIZE=100000

INVOKE		=	libft printf

IFLAGS		=	-Iinclude -Ilib/libft -Ilib/printf/include

LFLAGS		=	-Llib/libft -lft -Llib/printf -lftprintf -lm

ifeq ($(PLATFORM),Linux)
	MLX		=	lib/mlx_linux
	INVOKE	+=	mlx_linux
	IFLAGS	+=	-I/usr/include -Ilib/mlx_linux
	LFLAGS	+=	-Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(PLATFORM), Darwin)
	MLX		=	lib/mlx_mac
	INVOKE	+=	mlx_mac
	IFLAGS	+=	-Ilib/mlx_mac
	LFLAGS	+=	-Llib/mlx/mac -lmlx -framework OpenGL -framework AppKit
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

mlx_linux:
				@$(MAKE) $(MAKECMDGOALS) -C lib/mlx_linux

mlx_mac:
				@$(MAKE) $(MAKECMDGOALS) -C lib/mlx_mac

re:			fclean all

.PHONY:		all clean fclean re libft printf mlx_linux mlx_mac wait_msg
