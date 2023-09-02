#include "Router.h"

using namespace Routes;

Router::Router() {}
Router *Router::get()
{
    static Router* instance = new Router();
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
    vector<string> v(params, params + sizeof params);
    Router::get()->params = v;
}

void Router::executeRoute(string alias) {
    this->routes[alias]->execute(*(new Request(this->params)));
}
