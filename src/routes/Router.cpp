#include "Router.h"

using namespace Routes;

Router::Router() {}
Router *Router::get()
{
    static Router* instance = new Router();
    return instance;
}
void Router::add(Route *route)
{
    this->routes.push_back(route);
}
void Router::remove()
{
    this->routes.pop_back();
}
Route *Router::peek()
{
    return this->routes[this->routes.size() - 1];
}
bool Router::isEmpty()
{
    return this->routes.size() <= 0;
}
vector<Route *> Router::getAll()
{
    return Router::get()->routes;
}
void Router::executeMethod(string alias)
{
    Router::get()->mappedMethods[alias](*(new Request(Router::get()->params)));
}

void Router::setParams(char *params[])
{
    vector<string> v(params, params + sizeof params);
    Router::get()->params = v;
}
