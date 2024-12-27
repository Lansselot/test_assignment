#pragma once
#include "RequestHandler.h"
#include "../Storage/Storage.h"
#include "../Storage/MediaStorage.h"
class MessageHandler : public RequestHandler
{
protected:
    std::shared_ptr<Storage> messageStorage;
    std::shared_ptr<MediaStorage> mediaStorage;
public:
    explicit MessageHandler(std::shared_ptr<Storage> messageStoragePtr, std::shared_ptr<MediaStorage> mediaStoragePtr);

    void handleGet(Request& request, Response& response) override;
    void handlePost(Request& request, Response& response) override;
    void handlePut(Request& request, Response& response) override;
    void handleDelete(Request& request, Response& response) override;
    void handlePatch(Request& request, Response& response) override;
};
