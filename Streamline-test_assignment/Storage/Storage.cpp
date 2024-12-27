#include "Storage.h"

Storage::Storage(std::shared_ptr<IMessageStorageStrategy> messageStorageStrategy) : messageStorageStrategy(messageStorageStrategy) {}

void Storage::setStratege(std::shared_ptr<IMessageStorageStrategy> messageStorageStrategy)
{
    this->messageStorageStrategy = messageStorageStrategy;
}
int Storage::createMessage(const Message& message)
{
    return messageStorageStrategy->insertMessage(message);
}
bool Storage::deleteMessage(int messageID)
{
    return messageStorageStrategy->deleteMessage(messageID);

}
bool Storage::editMessage(int messageID, std::wstring& newText)
{
    return messageStorageStrategy->editMessage(messageID, newText);

}
std::vector<Message> Storage::getAllMessages(const User& user)
{
    return messageStorageStrategy->getAllMessages(user);
}