#include "MediaStorage.h"

MediaStorage::MediaStorage(std::shared_ptr<IMediaStorageStrategy> strategy) : mediaStorageStrategy(strategy) {}

void MediaStorage::setStratege(std::shared_ptr<IMediaStorageStrategy> mediaStorageStrategy)
{
    this->mediaStorageStrategy = mediaStorageStrategy;
}

std::string MediaStorage::saveMedia(const MediaFile& mediaFile)
{
    return mediaStorageStrategy->uploadMediafile(mediaFile);
}
bool MediaStorage::deleteMedia(const std::string& filePath)
{
    return mediaStorageStrategy->deleteMediafile(filePath);
}