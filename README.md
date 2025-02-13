# IRC Server - École 42 Project

This project is a simple implementation of an IRC (Internet Relay Chat) server, developed as part of the École 42 curriculum. The server allows multiple clients to connect, join channels, and communicate with each other in real-time.

## Features
- Supports multiple clients and channels.
- Basic IRC commands:
  - `/NICK <nickname>`: Set or change your nickname.
  - `/JOIN <channel>`: Join or create a channel.
  - `/PART <channel>`: Leave a channel.
  - `/PRIVMSG <target> <message>`: Send a message to a user or channel.
  - `/QUIT`: Disconnect from the server.
- Handles client connections and disconnections gracefully.
- Lightweight and easy to set up.

## Requirements
- A Unix-based system (Linux or macOS).
- GCC or Clang for compilation.
- Basic knowledge of sockets and networking.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/42-irc-server.git
   ```
2. Navigate to the project directory:
  ```
  cd 42-irc-server
  ```
3. Compile the server:
  ```
  make
  ```
## Usage
  ```
  ./ircserv <port> <password>
  ```
