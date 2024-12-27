#pragma once
#include "../Core/Message.h"
#include <vector>
class IMessageStorageStrategy
{
public:
    virtual ~IMessageStorageStrategy() {};

    virtual int insertMessage(const Message& message) = 0;
    virtual bool deleteMessage(int messageID) = 0;
    virtual bool editMessage(int messageID, std::wstring& newText) = 0;
    virtual std::vector<Message> getAllMessages(const User& user) = 0;
};;

