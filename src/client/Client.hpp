#ifndef CLIENT_HPP

#define CLIENT_HPP

#include "../user/User.hpp"

#include <cstring>
#include <string>
#include <sys/poll.h>

class Client
{
  public:
    Client(unsigned long ipv4, unsigned long port, int p_fd);
    ~Client();
    Client(const Client &);

    unsigned long      getIpv4() const { return _ipv4; }
    unsigned long      getPort() const { return _port; }

    const std::string &getNickname() const { return _nickname; }
    void               setNickname(const std::string &n) { _nickname = n; }

    const User        *getUser() const { return _user; }
    void               setUser(const User *user) { _user = user; };

    void               appendToBuffer(const char *data, size_t length) { _buffer.append(data, length); }

    std::string       &getBuffer() { return _buffer; }

    void               clearBufferUpTo(size_t pos) { _buffer.erase(0, pos); }

    int                getPollFd() const { return _poll_fd; }
    void               setPollFd(int p_fd) { _poll_fd = p_fd; }

    const Client      &operator=(const Client &);
    bool               operator==(const Client &) const;
    bool               operator!=(const Client &) const;
    bool               operator<(const Client &) const;
    bool               operator>(const Client &) const;

    int                receiveMessage(const std::string &) const;

    void               setAllowed(bool allowed) { _allowed = allowed; };
    bool               isAllowed() const { return _allowed; }

    void               setAuthenticated(bool authenticated) { _allowed = authenticated; }
    bool               isAuthenticated() const { return isAllowed() && _nickname != "" && _user != 0x00; }

  private:
    Client();
    unsigned long  _ipv4;
    unsigned short _port;
    int            _poll_fd;
    std::string    _buffer;
    bool           _allowed;

    std::string    _nickname;
    const User    *_user;
};

#endif // !CLIENT_HPP
