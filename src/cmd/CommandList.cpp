#include "Commands.hpp"

#define IRC_RPL_LISTSTART "321"
#define IRC_RPL_LIST      "322"
#define IRC_RPL_LISTEND   "323"

CommandList::CommandList(std::set<std::string> channels) : channels(channels) {}

CommandList::~CommandList() {}

CommandList::CommandList(const CommandList &commandList) { this->channels = commandList.channels; }

void CommandList::execute(Client *client, const Server &server)
{
  std::set<Channel *> publicChannels = server.getChannelManager()->findChannelsByIsPublic(true);
  std::set<Channel *> userChannels   = server.getChannelManager()->findChannelsByClient(client);

  userChannels.insert(publicChannels.begin(), publicChannels.end());

  client->receiveMessage(server.respond(IRC_RPL_LISTSTART, client));
  for (std::set<Channel *>::iterator it = userChannels.begin(); it != userChannels.end(); ++it)
  {
    client->receiveMessage(server.respond(
        IRC_RPL_LIST, client, (*it)->getName() + " " + (*it)->getUserCountString() + " :" + (*it)->getTopic()
    ));
  }

  client->receiveMessage(server.respond(IRC_RPL_LISTEND, client));
}

bool CommandList::canExecute(Client *client, const Server &server)
{
  (void)server;
  if (client->isAuthenticated() == false)
  {
    client->receiveMessage("451 " + client->getNickname() + " :You have not registered");
    return false;
  }
  return true;
}

void CommandList::execute(const Client *client, const Server &server) { execute(const_cast<Client *>(client), server); }

bool CommandList::canExecute(const Client *client, const Server &server)
{
  return canExecute(const_cast<Client *>(client), server);
}
