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

using namespace std;
using namespace Requests;
template <typename T>
using ControllerMethod = string (T::*)(Request);

namespace Routes
{
    class Router
    {
    private:
        vector<Route *> routes;
        vector<string> params;
        map<string, function<string(Request)>> mappedMethods;

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
        void addRoute(string path, string methodAlias, ControllerMethod<T> method)
        {
            Router::get()->mapMethod<T>(methodAlias, method);
            Router::get()->add(new Route(path));
        }

    private:
        template <typename T>
        void mapMethod(string alias, ControllerMethod<T> method)
        {
            function<string(Request)> func = [method](Request request)
            {
                T controller;
                return (controller.*method)(request);
            };
            Router::get()->mappedMethods[alias] = func;
        }
    };

}