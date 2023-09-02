#pragma once
#include "string"
#include "../requests/Request.h"
#include "map"
#include "functional"
#include "ControllerMethod.h"

using namespace std;
using namespace Requests;

namespace Routes
{
    class Route
    {
    private:
        string path;
        function<void(Request)> method;

    public:
        Route(string path);
        template <typename T>
        void setMethod(ControllerMethod<T> method)
        {
            std::function<void(Request)> func = [method](Request request)
            {
                T controller;
                return (controller.*method)(request);
            };
            this->method = func;
        }

        void execute(Request req);
        string getPath();
    };
}