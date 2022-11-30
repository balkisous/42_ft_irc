/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 17:47:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>
#include "channel/channel.hpp"
#include "user/user.hpp"

#define END = "\r\n"


    class Server
    {
        private:
            //We don't need it cause it is in <poll.h>
            // struct pollfd 
            // {
            //     int   fd;         /* file descriptor */
            //     short events;     /* requested events */
            //     short revents;    /* returned events */
            // };
            
            time_t last_ping;
            time_t heartbeat;
            
            int _port;
            std::vector<pollfd> fds;
            //std::vector<Channel> channels; //contains all channels
            //std::map<unsigned int, User> users; //contains all users as pair of: fd of the user and the user 

        public:
            Server();
            Server(Server &lhs);
            ~Server();
        

            void init();
            void execute();
    };

#endif