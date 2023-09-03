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
    this->routes[index] = route;
}
void Router::remove(string index)
{
    delete this->routes[index];
}
bool Router::isEmpty()
{
    return this->routes.size() <= 0;
}

void Router::setParams(int paramsSize, char *params[])
{
    vector<string> v;

    for (int i = 1; i < paramsSize; ++i)
    {
        if (params[i] != nullptr)
            v.push_back(params[i]);
    }

    if (this->params.size() > 0)
        Router::get()->params = v;
}

void Router::executeRoute()
{
    const string requestedRoute = this->getRequestedRoute();
    if (!this->routeExists(requestedRoute))
        throw new Exceptions::Exception("Rota não existe!");

    this->routes[requestedRoute]->execute(*(new Request(this->params)));
}

string Router::getRequestedRoute()
{
    return this->hasPassedRoute() ? this->params[0] : DEFAULT_APP_ROUTE;
}

bool Router::hasPassedRoute()
{
    return this->params.size() > 0;
}

bool Router::routeExists(string route)
{
    return this->routes[route] != nullptr;
}