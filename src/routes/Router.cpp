#include "Router.h"

using namespace Routes;

Router::Router() {}
Router* Router::get() {
    static Router* instance = new Router();
    return instance;
}
void Router::add(Route *route) {
    this->routes.push_back(route);
}
void Router::remove() {
    this->routes.pop_back();
}
Route* Router::peek() {
    return this->routes[this->routes.size() - 1];
}
bool Router::isEmpty() {
    return this->routes.size() <= 0;
}
vector<Route*> Router::getAll() {
    return Router::get()->routes;
}
void Router::addRoute(string path) {
    Router::get()->add(new Route(path));
}