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
    const string DEFAULT_APP_ROUTE = "index";
    class Router
    {
    private:
        map<string, Route *> routes;
        vector<string> params;

        Router();
        void insert(string index, Route *route);
        void remove(string index);
        bool isEmpty();
        bool hasPassedRoute();
        string getRequestedRoute();

    public:
        static Router *get();
        void executeRoute();
        bool routeExists(string route);
        void setParams(int paramsSize, char *params[]);
        template <typename T>
        void addRoute(string path, ControllerMethod<T> method)
        {
            if(path == "")
                path = DEFAULT_APP_ROUTE;
            Route* route = new Route(path);
            route->setMethod<T>(method);
            Router::get()->insert(path, route);
        }        
    };

}