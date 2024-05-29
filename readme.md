# Ft_Irc 💬
Created an Irc server.

## Description 🔍

The objective of this project is to reproduce the operation of an IRC (Internet Relay Chat) server, so that several IRC clients can connect; carried out in a group.
     This project allowed me to code for the first time a large project in OOP, it was very interesting to wonder which object we can create or which functions or attributes it can have. The analysis was stimulating 😊.

## Getting started 🏁

### Dependencies 🛠️
* Basic bash
* Terminal
* Irssi client 
* Netcat client (nc)
* Work on Linux

### Installation 📦
* Command make for the Makefile

### Running the program 💻
* How to run the program
* First clone it
  ```
  git clone https://github.com/balkisous/Ft_Irc.git ```
* Change directory and make to compile
  ```
  ~ cd Ft_Irc && make
  ~ ./ircserv -c localhost -p [port] -w [password] -n [name]
  Ex : irssi -c localhost -p 1555 -w 123pass -n balkis
  ```
* Open a new terminal and Test with irssi client or nc client
* With irssi : 
	``` ~ irssi -c localhost -p [port] ```
* With nc :
	```
	~ nc localhost [port]
 	PASS serverpass
	NICK marie
	USER marie 0 * :marie
	JOIN #chan
	PART #chan
	```

 ## Excepted view
 [ft_irc.webm](https://github.com/balkisous/Ft_Irc/assets/76943138/0b935986-13f3-43fa-b3de-79ad62678fa6)

## Help 🛟
Read the IRC documentation to understand how to connect and how it's works.
	L-> https://modern.ircdocs.horse/ (Go in client Messages)
    
## Authors 👩‍💻
Names of contributors :
* @marieines7
* @dediane
* @balkisous
## Version history ✅
* Made at 42Paris 

## Subject 📝
You will find the subject in the repository.
