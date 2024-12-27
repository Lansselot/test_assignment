#pragma once
#include "../Core/Request.h"
#include "../Core/Response.h"
class RequestHandler
{
public:
    void handle(Request& request, Response& response);
    virtual ~RequestHandler() {};


    virtual void handleGet(Request& request, Response& response) = 0;
    virtual void handlePost(Request& request, Response& response) = 0;
    virtual void handlePut(Request& request, Response& response) = 0;
    virtual void handleDelete(Request& request, Response& response) = 0;
    virtual void handlePatch(Request& request, Response& response) = 0;
};
