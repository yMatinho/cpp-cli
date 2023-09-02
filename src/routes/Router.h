#pragma once
#include "vector"
#include "string"
#include "../app/controllers/Controller.h"
#include "../app/controllers/GradesController.h"
#include "Route.h"
#include "../requests/Request.h"
#include "map"
#include "functional"
#include "any"
#include "iostream"
#include "ControllerMethod.h"

using namespace std;
using namespace Requests;

namespace Routes
{
    class Router
    {
    private:
        vector<Route *> routes;
        vector<string> params;

        Router();
        void add(Route *route);
        void remove();
        Route *peek();
        bool isEmpty();
        void executeMethod(string alias);

    public:
        static Router *get();
        vector<Route *> getAll();
        void setParams(char *params[]);
        template <typename T>
        void addRoute(string path, ControllerMethod<T> method)
        {
            Route* route = new Route(path);
            route->setMethod<T>(method);
            Router::get()->add(route);
        }        
    };

}