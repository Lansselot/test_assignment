#include "MessageHandler.h"

MessageHandler::MessageHandler(std::shared_ptr<Storage> messageStoragePtr, std::shared_ptr<MediaStorage> mediaStoragePtr) : messageStorage(messageStoragePtr), mediaStorage(mediaStoragePtr) {}

void MessageHandler::handleGet(Request& request, Response& response)
{
    User user{ 0, L"Petro", L"Petrenko" }; //example user from the request

    auto messages = messageStorage->getAllMessages(user);

    if (!messages.empty())
    {
        //Success, set in response 
    }
    else
    {
        //Failure, error in response 
    }
}

void MessageHandler::handlePost(Request& request, Response& response)
{
    User user1{ 0, L"Petro", L"Petrenko" }; //example user from the request
    User user2{ 0, L"Vasyl", L"Vasylenko" }; //example user from the request
    std::wstring messageText = L"Message text"; //example message text from the request

    MediaFile mediaFile{ "\\example\\path\\", "filename", "png" }; //example mediaFile from the request (if exist)
    auto mediaFilePath = mediaStorage->saveMedia(mediaFile);

    Message message{
        0, //id will be created later
        messageText,
        user1,
        user2,
        std::chrono::system_clock::now(),
        std::nullopt,
        mediaFilePath
    }; //example message

    int messageID = messageStorage->createMessage(message);
    if (messageID > 0)
    {
        //Success, set in response 
    }
    else
    {
        //Failure, error in response 
    }
}

void MessageHandler::handlePut(Request& request, Response& response)
{
    //not implemented, error in response 
}

void MessageHandler::handleDelete(Request& request, Response& response)
{
    int messageID = 1; //example message ID from the request

    bool success = messageStorage->deleteMessage(messageID);
    if (success)
    {
        //Success, set in response 
    }
    else
    {
        //Failure, error in response 
    }
}

void MessageHandler::handlePatch(Request& request, Response& response)
{
    int messageID = 1; //example message ID from the request
    std::wstring newText = L"New message text"; //example message edited text from the request

    bool success = messageStorage->editMessage(messageID, newText);
    if (success)
    {
        //Success, set in response 
    }
    else
    {
        //Failure, error in response 
    }
}