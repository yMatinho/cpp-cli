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

void Router::setParams(char *params[])
{
    const int maxParameters = 10;
    vector<string> v;

    for (int i = 1; i < maxParameters; ++i)
    {
        if (params[i] != nullptr)
            v.push_back(params[i]);
    }

    Router::get()->params = v;
}

void Router::executeRoute()
{
    if (!this->routeExists(this->params[0]))
        throw new Exceptions::Exception("Rota não existe!");
    this->routes[this->params[0]]->execute(*(new Request(this->params)));
}

bool Router::routeExists(string route)
{
    return this->routes[route] != nullptr;
}
