#pragma once
#include "User.h"
#include "Common.h"
#include <string>
#include <optional>

struct Message
{
    int id;
    std::wstring text;
    User sender, receiver;
    Timestamp created;
    std::optional<Timestamp> lastEdited;
    std::optional<std::string> mediaFilePath;
};
