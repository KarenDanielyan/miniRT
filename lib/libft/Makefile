NAME		=	libft.a

DEP			= 	libft.h get_next_line.h Makefile

SOURCES		=	$(shell find . -maxdepth 1 -name '*.c')

OBJS		=	$(patsubst %.c, $(BUILD)/%.o, $(SOURCES))

BUILD		=	./build

CC			=	cc

RM			=	rm -rf

CFLAGS		=	-g3 -Wall -Wextra -Werror

AR			=	ar rcs

# Colors
RESET  = \033[0m
GREEN  = \033[32m
BLUE   = \033[34m
YELLOW = \033[0;93m

$(BUILD)/%.o:	%.c $(DEP)
				@echo "${BLUE}Compiling $<${RESET}" 
				@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(BUILD) $(OBJS)
				@echo "${GREEN}Building Libft...${RESET}"
				@$(AR) $(NAME) $(OBJS)
				@echo "${GREEN}Done.${RESET}"

$(BUILD):
			@mkdir $(BUILD)

clean:		
				@echo "${YELLOW}Cleaning build${RESET}"
				@$(RM) $(BUILD)

fclean:
				@echo "${YELLOW}Cleaning Everyting${RESET}"
				@$(RM) $(BUILD)
				@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all bonus clean fclean re