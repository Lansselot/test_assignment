#include "Handlers/MessageHandler.h"
#include "Storage/Strategies/DBMessageStorage.h"
#include "Storage/Strategies/LocalMediaStorage.h"
#include <iostream>


int main()
{
    try {
        auto messageStorageStrategy = std::make_shared<DBMessageStorage>("test_database_path");
        auto mediaStorageStrategy = std::make_shared<LocalMediaStorage>();

        auto messageStorage = std::make_shared<Storage>(messageStorageStrategy);
        auto mediaStorage = std::make_shared<MediaStorage>(mediaStorageStrategy);

        MessageHandler messageHandler(messageStorage, mediaStorage);

        MediaFile mediaFile{ "MediaFile path", "test.png", "png", 2048 };
        std::string mediaPath = mediaStorage->saveMedia(mediaFile);
        std::cout << "Media file saved at " << mediaPath << std::endl;

        mediaStorage->deleteMedia(mediaPath);
        std::cout << "Media file deleted" << std::endl;

        User sender{ 1, L"Petro", L"Petrenko" };
        User receiver{ 2, L"Vasyl", L"Vasylenko" };

        Message message{
            0,
            L"test message",
            sender,
            receiver,
            std::chrono::system_clock::now(),
            std::nullopt,
            std::nullopt
        };

        int messageID = messageStorage->createMessage(message);
        std::wcout << "Message created with ID = " << messageID << std::endl;

        auto messages = messageStorage->getAllMessages(sender);
        std::wcout << "Messages for user " << sender.name << std::endl;

        for (auto& msg : messages) {
            std::wcout << msg.id << " " << msg.text << std::endl;
        }

        std::wstring newText = L"updated test message";
        messageStorage->editMessage(messageID, newText);
        std::wcout << "Message updated" << std::endl;

        messageStorage->deleteMessage(messageID);
        std::wcout << "Message deleted" << std::endl;


        Request request;
        Response response;

        messageHandler.handleGet(request, response);
        std::cout << "handleGet" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
   
    return 0;
}