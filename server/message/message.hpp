/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:39 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/06 13:49:22 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "main.hpp"

class Message
{
    class Server;
    class User;
    public:
        Message();
        Message(Message &lhs);
        ~Message();
    private:
       User *_user;
       Server *_server;

       bool cmd;
       std::string command;
       std::vector<std::string> message;
};

#endif