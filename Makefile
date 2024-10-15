NAME		= irc
SRC			=  src/main.cpp \
			   src/Server.cpp \
			   src/channel/Channel.cpp \
			   src/channel/ChannelManager.cpp \
			   src/client/Client.cpp \
			   src/client/ClientManager.cpp \
			   src/cmd/CommandManager.cpp \
			   src/cmd/CommandPass.cpp \
			   src/cmd/CommandPrivmsg.cpp \
			   src/cmd/CommandNotice.cpp \
			   src/cmd/CommandNick.cpp \
			   src/cmd/CommandUser.cpp \
			   src/cmd/CommandList.cpp \
			   src/cmd/CommandPing.cpp \
			   src/cmd/CommandJoin.cpp \
			   src/cmd/CommandCap.cpp \
			   src/cmd/CommandQuit.cpp \
			   src/cmd/CommandPart.cpp \
			   src/cmd/CommandTopic.cpp \
			   src/password/PasswordManager.cpp \
			   src/user/User.cpp \
			   src/user/UserManager.cpp
OBJ			= $(SRC:.cpp=.o)
CXX			= clang++
RM			= rm -rf
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
