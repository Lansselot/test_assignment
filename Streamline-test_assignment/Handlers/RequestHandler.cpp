#include "RequestHandler.h"

void RequestHandler::handle(Request& request, Response& response)
{
    switch (request.type())
    {
    case RequestType::GET: {
        handleGet(request, response);
        return;
    }
    case RequestType::POST: {
        handlePost(request, response);
        return;
    }
    case RequestType::PUT: {
        handlePut(request, response);
        return;
    }
    case RequestType::DELETE: {
        handleDelete(request, response);
        return;
    }
    case RequestType::PATCH: {
        handlePatch(request, response);
        return;
    }
    default: {
        //Failure, error in response 
    }
    }
}
