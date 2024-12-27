#pragma once
#include "../../Interfaces/IMediaStorageStrategy.h"
#include <mutex>

class LocalMediaStorage : public IMediaStorageStrategy
{
private:
    std::mutex mediaMutex;
public:
    std::string uploadMediafile(const MediaFile& mediaFile) override;
    bool deleteMediafile(const std::string& filePath) override;
};
