/**
    TwitchIRC.h
    PhantomBot Project
    By: Robert F. (Phantom139)
    Built on Ubuntu 14.04.10 LTS
**/

#ifndef _TWITCHCOMMANDLIMIT_H
#define _TWITCHCOMMANDLIMIT_H

#include "../include.h"
#include "../Lib/lib.h"
#include "Admin.h"

/*
TwitchCommandLimit Struct
Class instance used to protect the bot from going over the command limit
*/
struct TwitchCommandLimit {
    /* Class Enumerations */
    enum TwitchLimits {
        //How many commands can we send in a 30 second period
        COMMAND_LIMIT_NORMAL = 15,
        //If we're a op/mod, how many?
        COMMAND_LIMIT_OPMOD = 95,
        //How many spaces are we allocating for "forced" commands
        COMMAND_LIMIT_FORCED = 5,
    };

    /* Methods */
    //Constructor
    TwitchCommandLimit(Socket *sO, Admin *a, std::string cName);
    //Process the USERSTATE message
    void ProcessUserState(const std::string command);
    //Add a command to the process queue
    void AddCommand(const std::string command);
    //Push a command through the pipe.
    void PushCommand(const std::string command);
    //Update, called by TwitchIRC on it's update cycle
    void Update();
    //Return the name of the active channel
    const std::string Channel() const;
    //Wrapper to send with error check
    void SendCommand(const std::string command);
    //Expose the Admin object
    Admin *adminObj() const;

    private:
        /* Members */
        //The name of the channel
        std::string channel;
        //The Queue of commands that will be processed
        std::queue<std::string> commands;
        //How many commands have we sent from the last 30s update?
        int currentSendCount;
        //How many forced commands have we sent in the last 30s update?
        int forcedSendCount;
        //Do we have mod status?
        bool isModOrOp;
        //The timeval at the time of the currentSendCount initiation
        timeval curTVal;
        //The timeval at the time of the forcedSendCount initiation
        timeval curFVal;
        //Attached socket instance
        Socket *aSock;
        //Attached admin instance
        Admin *aAdmin;
};

#endif //_TWITCHCOMMANDLIMIT_H