#ifndef SERVER_HPP

#define SERVER_HPP

#include "cmd/CommandHandler.hpp"
#include "password/APassword.hpp"
#include "password/PasswordManager.hpp"
#include "client/ClientManager.hpp"

#include <string>

class Server
{
  public:
    Server(unsigned short port, std::string passwordString);
    ~Server();

    // void addChannel(Channel *channel);
    // void validateChannel(Channel *channel);
    // void removeChannel(Channel *channel);

    // void addClient(Client *client);
    // void validateClient(Client *client);
    // void removeClient(Client *client);

    unsigned short getPort() const { return port; }

    void           start();

  private:
    int             socket_fd;
    unsigned short  port;
    APassword       password;

    PasswordManager passwordManager;
    CommandHandler  *commandHandler;
		ClientManager  *clientManager;
};

#endif // !SERVER_HPP
