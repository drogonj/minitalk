CLIENTNAME	 =   client
SERVERNAME   =   server

CLIENTSRCS   =   client.c
SERVERSRCS   =   server.c

CLIENTOBJS   =   $(CLIENTSRCS:.c=.o)
SERVEROBJS   =   $(SERVERSRCS:.c=.o)

CLIENTNAMEB	 =   client_bonus
SERVERNAMEB  =   server_bonus

CLIENTSRCSB  =   client_bonus.c
SERVERSRCSB  =   server_bonus.c

CLIENTOBJSB  =   $(CLIENTSRCSB:.c=.o)
SERVEROBJSB  =   $(SERVERSRCSB:.c=.o)

FT_PRINTF	 =	ft_printf/libftprintf.a

FLAGS		 =	-Wall -Wextra -Werror -g3

RM			 =	rm -rf

.c.o:
			    gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:			$(SERVERNAME) $(CLIENTNAME)

bonus:			$(SERVERNAMEB) $(CLIENTNAMEB)

$(CLIENTNAME):	$(CLIENTOBJS)
				gcc $(FLAGS) $(CLIENTOBJS) $(FT_PRINTF) -o $(CLIENTNAME)

$(SERVERNAME):	$(SERVEROBJS)
				$(MAKE) -C ft_printf
				gcc $(FLAGS) $(SERVEROBJS) $(FT_PRINTF) -o $(SERVERNAME)

$(CLIENTNAMEB):	$(CLIENTOBJSB)
				gcc $(FLAGS) $(CLIENTOBJSB) $(FT_PRINTF) -o $(CLIENTNAMEB)

$(SERVERNAMEB):	$(SERVEROBJSB)
				$(MAKE) -C ft_printf
				gcc $(FLAGS) $(SERVEROBJSB) $(FT_PRINTF) -o $(SERVERNAMEB)
clean:
			    $(RM) $(CLIENTOBJS) $(SERVEROBJS) $(CLIENTOBJSB) $(SERVEROBJSB)
				$(MAKE) -C ft_printf clean

fclean:			clean
				$(RM) $(CLIENTNAME) $(SERVERNAME) $(CLIENTNAMEB) $(SERVERNAMEB)
				$(MAKE) -C ft_printf fclean

re:				fclean all

.PHONY:			all clean fclean re bonus