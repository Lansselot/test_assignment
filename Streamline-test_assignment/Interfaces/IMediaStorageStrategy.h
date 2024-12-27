#pragma once
#include <string>
#include "../Core/Mediafile.h"
class IMediaStorageStrategy
{
public:
    virtual ~IMediaStorageStrategy() {};

    virtual std::string uploadMediafile(const MediaFile& mediaFile) = 0;
    virtual bool deleteMediafile(const std::string& filePath) = 0;
};