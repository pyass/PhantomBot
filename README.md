# Phantom Bot Twitch IRC Project #
## By Robert C. Fritzen (Phantom139) ##
## Written & Compiled on Ubuntu 14.04.1 LTS ##

### Prerequisites ###
No Libraries Required!!! This project uses all native Linux code. You'll just need the 'cmake' package to build it!

### Setup Instructions ###
Drop the files into a directory and open a terminal. cd to the directory and run the command 'cmake . && make' to compile, then run the code with ./PhantomBot

### Configuration Files ###
There are two bot config files you can use.

1. botconfig.txt contains information you'll need to obtain to run the bot You'll need to insert your account name associated with the bot, and the channel name of the channel you'd like the bot to be active in. Finally, you'll need to obtain your oauth code from Twitch. To obtain this, log into your bot account and naviagte to this link: http://twitchapps.com/tmi/ Copy the contents of the page and then paste it into the oauth line.
2. adminusers.txt is a line delimited file of usernames who will have "admin status" on bot commands. These users will have elevated permissions.

### Additional Info ###
This bot contains all of the basics you'll need to get going. See the TwitchPrivMsg.cpp file for examples on how to set up custom commands. The TwitchIRC.cpp file contains all of the initialization code you'll need to use the bot in channels. You may encounter some bugs or issues, please report them here so they can be fixed, and please contribute here if you have stuff to add! This is a freebie project I'm giving out for people to use and learn from, so feel free to use it!
