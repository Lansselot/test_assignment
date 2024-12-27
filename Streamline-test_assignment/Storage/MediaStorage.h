#pragma once
#include "Strategies/LocalMediaStorage.h"
#include "../Interfaces/IMediaStorageStrategy.h"
#include <memory>

class MediaStorage
{
private:
    std::shared_ptr<IMediaStorageStrategy> mediaStorageStrategy;

public:
    explicit MediaStorage(std::shared_ptr<IMediaStorageStrategy> strategy);

    void setStratege(std::shared_ptr<IMediaStorageStrategy> mediaStorageStrategy);
    std::string saveMedia(const MediaFile& mediaFile);
    bool deleteMedia(const std::string& filePath);
};