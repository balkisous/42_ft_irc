/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:58:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/05 23:24:20 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

User::User()
{
}

User::User(int newfd, sockaddr_in address)
{
    fd = newfd;
    _hostaddr = inet_ntoa(address.sin_addr); //convert host addr in a string
    fcntl(fd, F_SETFL, O_NONBLOCK);
    char buffer[NI_MAXHOST];
    if (getnameinfo((sockaddr *)&address, sizeof(address), buffer, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) == -1)
        std::cout << "error getnameinfo" << std::endl;
    _hostname = buffer;
}

User::User(const User &lhs)
{
    this->fd = lhs.fd;
    this->_nickname = lhs._nickname;
    this->_hostname = lhs._hostname;

}

User::~User()
{
    
}

User &User::operator=(const User &lhs)
{
    this->_nickname = lhs._nickname;
    this->fd = lhs.fd;
    this->_hostname = lhs._hostname;
    return (*this);
}

void User::receive()
{
    char buffer[BUFFER_SIZE + 1];
    
    ssize_t response_size = recv(fd, buffer, BUFFER_SIZE, 0);
    if (response_size == -1)
        return;
    //std::cout << buffer << std::endl;
    //std::cout << response_size << std::endl;
    if (response_size == 0)
        return;
    buffer[response_size] = 0;
    user_buffer = user_buffer + buffer;
    //std::cout << user_buffer << std::endl;
    split_buffer(user_buffer);
    //exec_command();
}

void User::split_buffer(std::string str)
{
    std::string tofind = "\r\n";
    int index = 0;
    while ((index = str.find(tofind, index)) != (int)(std::string::npos)) 
    {
        std::string tmp;
        for(int i = 0; i < index; i++)
            tmp.push_back(str[i]);
        tmp.append(tofind);
        _messages.push_back(tmp);
        tmp.clear();
        index += tofind.length();
        str.erase(0, index);
        index = 0;
        _numberCmd++;
    }
    return;
    // std::vector<std::string>::iterator it;
    // for (it = _messages.begin(); it != _messages.end(); it++)
    //     std::cout << *it; 
}

/***********/
/*Accessors*/
/***********/

void User::setNickname(std::string nickname) {_nickname = nickname; return;}
void User::setUsername(std::string username) {_username = username; return;}
void User::setRealname(std::string realname) {_realname = realname; return;}
void User::setHostname(std::string hostname) {_hostname = hostname; return;}
void User::setHostAddr(std::string hostaddr) {_hostaddr = hostaddr; return;}
void User::setLastPing(time_t last_ping) {_last_ping = last_ping; return;}

std::string User::getNickname() {return (_nickname);}
std::string User::getUsername() {return (_username);}
std::string User::getRealname() {return (_realname);}
std::string User::getHostname() {return (_hostname);}
std::string User::getHostAddr() {return (_hostaddr);}
std::string User::getPrefix() {return (":" + _nickname + "!" + _username + "@" + _hostname);}

bool User::isRegistered() {return (_registered);}
bool User::isOnline() {return (_online);}
bool User::isDeleted() { return (_deleted);}