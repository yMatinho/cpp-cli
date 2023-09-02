#include "Route.h"

using namespace Routes;
Route::Route(string path)
{
    this->path = path;
}
string Route::getPath()
{
    return this->path;
}

void Route::execute(Request req) {
    this->method(req);
}