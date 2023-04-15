CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJECTS = $(SRCS:.c=.o)
# BNSSRCS =
# BNSOBJECTS = $(BNSSRCS:.c=.o)
INC = -I./get_next_line.h
ARRCS = ar rcsu
RMF = rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(ARRCS) $(NAME) $(OBJECTS)

# bonus :
# 	@$(MAKE) OBJECTS='$(OBJECTS) $(BNSOBJECTS)' all

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean :
	$(RMF) $(OBJECTS) $(BNSOBJECTS)

fclean : clean
	$(RMF) $(NAME) 

re : fclean all

.PHONY : claen fclaen all re bonus