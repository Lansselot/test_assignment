#pragma once
#include <chrono>

using Timestamp = std::chrono::time_point<std::chrono::system_clock>;

enum class RequestType
{
    GET,
    POST,
    PUT,
    DELETE,
    PATCH
};
