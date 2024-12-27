#include "DBMessageStorage.h"
#include <string>

DBMessageStorage::DBMessageStorage(const std::string& path)
{
    //Connect to BD
}

DBMessageStorage::~DBMessageStorage()
{
    //Close DB connection
}

int DBMessageStorage::insertMessage(const Message& message)
{
    std::lock_guard<std::mutex> lock(dbMutex);
    //WORK WITH DB
    return 1;
}

bool DBMessageStorage::deleteMessage(int messageID)
{
    std::lock_guard<std::mutex> lock(dbMutex);
    //WORK WITH DB
    return true;
}

bool DBMessageStorage::editMessage(int messageID, std::wstring& newText)
{
    std::lock_guard<std::mutex> lock(dbMutex);
    //WORK WITH DB
    return true;
}

std::vector<Message> DBMessageStorage::getAllMessages(const User& user)
{
    std::lock_guard<std::mutex> lock(dbMutex);
    //WORK WITH DB
    return {};
};