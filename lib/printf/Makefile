NAME		=	libftprintf.a

INCLUDE		=	./include

BUILD		=	./build

SRC			=	./source

DEP			=	$(INCLUDE)/ft_printf.h Makefile

SOURCES		=	$(wildcard $(SRC)/*.c)

OBJS		=	$(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))

CC 			= 	cc

RM			=	rm -rf

CFLAGS		=	-g3 -Wall -Wextra -Werror -Wpedantic

LFLAGS		=

IFLAGS		=	-I./include

AR			=	ar rcs

$(BUILD)/%.o:	$(SRC)/%.c	$(DEP)
				@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

all:		$(NAME)

$(BUILD):
				@mkdir $(BUILD)

$(NAME):	$(BUILD) $(OBJS)
				@echo "Building printf..."
				@$(AR) $(NAME) $(OBJS)
				@echo Done.

clean:		
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_B)
				@$(RM) $(BUILD)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all bonus clean fclean re
