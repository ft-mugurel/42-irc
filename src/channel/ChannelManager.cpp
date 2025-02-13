#include "ChannelManager.hpp"

#include <stdexcept>
#include <string>

using std::map;
using std::pair;
using std::set;
using std::string;

ChannelManager::ChannelManager() {}

ChannelManager::~ChannelManager() {}

ChannelManager &ChannelManager::getInstance()
{
  static ChannelManager instance;
  return instance;
}

void ChannelManager::addChannel(const Channel &channel)
{
  if (this->_channels.find(channel.getName()) == this->_channels.end())
    this->_channels.insert(pair<string, Channel>(channel.getName(), Channel(channel)));
  else
    throw std::runtime_error("Channel already exists");
}

void     ChannelManager::removeChannel(const Channel *channel) { this->_channels.erase(channel->getName()); }

Channel *ChannelManager::findChannelByName(const string &name)
{
  string search = name[0] != '#' ? "#" + name : name;
  map<string, Channel>::iterator it = this->_channels.find(search);
  if (it != this->_channels.end())
    return &it->second;
  return 0x00;
}

set<Channel *> ChannelManager::findChannelsByIsPublic(bool isPublic)
{
  set<Channel *>                 channels;
  map<string, Channel>::iterator it;

  for (it = this->_channels.begin(); it != this->_channels.end(); ++it)
  {
    if (it->second.isPrivate() != isPublic)
      channels.insert(&it->second);
  }

  return channels;
}

set<Channel *> ChannelManager::findChannelsByClient(Client *client)
{
  set<Channel *>                 channels;
  map<string, Channel>::iterator it;

  for (it = this->_channels.begin(); it != this->_channels.end(); ++it)
  {
    if (it->second.hasUser(client->getUser()))
      channels.insert(&it->second);
  }

  return channels;
}

void ChannelManager::removeUserFromChannels(const User *user)
{
  map<string, Channel>::iterator it;

  for (it = this->_channels.begin(); it != this->_channels.end(); ++it)
    it->second.removeUser(user);
}

void ChannelManager::removeUserFromChannel(const User *user, const Channel *channel)
{
  Channel &ch = this->_channels.find(channel->getName())->second;
  ch.removeUser(user);
  if (ch.shouldDestroy())
  {
    this->_channels.erase(channel->getName());
  }
}
