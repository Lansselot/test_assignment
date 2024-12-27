#pragma once
#include "../Interfaces/IMessageStorageStrategy.h"
#include <memory>
class Storage
{
private:
    std::shared_ptr<IMessageStorageStrategy> messageStorageStrategy;

public:
    explicit Storage(std::shared_ptr<IMessageStorageStrategy> messageStorageStrategy);

    void setStratege(std::shared_ptr<IMessageStorageStrategy> messageStorageStrategy);
    int createMessage(const Message& message);
    bool deleteMessage(int messageID);
    bool editMessage(int messageID, std::wstring& newText);
    std::vector<Message> getAllMessages(const User& user);
};

