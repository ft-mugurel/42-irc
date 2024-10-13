#ifndef SERVER_HPP

#define SERVER_HPP

#include "channel/ChannelManager.hpp"
#include "client/ClientManager.hpp"
#include "cmd/CommandManager.hpp"
#include "password/Password.hpp"
#include "password/PasswordManager.hpp"

#include <string>

class Server
{
  public:
    Server(unsigned short port, std::string passwordString);
    ~Server();

    unsigned short   getPort() const { return port; }
    const Password  *getPassword() const { return password; }

    PasswordManager *getPasswordManager() const { return passwordManager; }
    ClientManager   *getClientManager() const { return clientManager; }
    CommandManager  *getCommandManager() const { return commandHandler; }
    ChannelManager  *getChannelManager() const { return channelManager; }

    std::string respond(std::string code, const Client *client, std::string message = "") const;
    std::string respond(std::string code, const Client *client, std::string message = "");

    void        start();

  private:
    int              socket_fd;
    unsigned short   port;
    const Password  *password;

    PasswordManager *passwordManager;
    CommandManager  *commandHandler;
    ClientManager   *clientManager;
    ChannelManager  *channelManager;
};

#endif // !SERVER_HPP
