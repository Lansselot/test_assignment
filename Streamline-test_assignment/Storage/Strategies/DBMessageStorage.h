#pragma once
#include "../../Interfaces/IMessageStorageStrategy.h"
#include <mutex>

class DBMessageStorage : public IMessageStorageStrategy
{
private:
    std::mutex dbMutex;
public:
    explicit DBMessageStorage(const std::string& path);
    ~DBMessageStorage() override;

    int insertMessage(const Message& message) override;
    bool deleteMessage(int messageID) override;
    bool editMessage(int messageID, std::wstring& newText) override;
    std::vector<Message> getAllMessages(const User& user) override;
};