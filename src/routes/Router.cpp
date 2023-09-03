#include "Router.h"
#include "iostream"
#include "../app/exceptions/Exception.h"

using namespace Routes;

Router::Router() {}
Router *Router::get()
{
    static Router *instance = new Router();
    return instance;
}
void Router::insert(string index, Route *route)
{
    Router::get()->routes[index] = route;
}
void Router::remove(string index)
{
    delete Router::get()->routes[index];
}
bool Router::isEmpty()
{
    return Router::get()->routes.size() <= 0;
}

void Router::setParams(int paramsSize, char *params[])
{
    vector<string> v;

    for (int i = 1; i < paramsSize; ++i)
    {
        if (params[i] != nullptr)
            v.push_back(params[i]);
    }

    if (v.size() > 0)
        Router::get()->params = v;
}

void Router::executeRoute()
{
    const string requestedRoute = Router::get()->getRequestedRoute();
    if (!Router::get()->routeExists(requestedRoute))
        throw new Exceptions::Exception("Rota não existe!");

    Router::get()->routes[requestedRoute]->execute(*(new Request(Router::get()->params)));
}

string Router::getRequestedRoute()
{
    return Router::get()->hasPassedRoute() ? Router::get()->params[0] : DEFAULT_APP_ROUTE;
}

bool Router::hasPassedRoute()
{
    return Router::get()->params.size() > 0;
}

bool Router::routeExists(string route)
{
    return Router::get()->routes[route] != nullptr;
}