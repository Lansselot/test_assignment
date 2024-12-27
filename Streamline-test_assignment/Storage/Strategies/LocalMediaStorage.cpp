#include "LocalMediaStorage.h"

std::string LocalMediaStorage::uploadMediafile(const MediaFile& mediaFile)
{
    std::lock_guard<std::mutex> lock(mediaMutex);
    //upload media to storage
    return "path";
}
bool LocalMediaStorage::deleteMediafile(const std::string& filePath)
{
    std::lock_guard<std::mutex> lock(mediaMutex);
    //delete media from storage
    return true;
}