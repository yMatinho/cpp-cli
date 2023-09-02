#include "vector"
#include "string"
#include "../app/controllers/Controller.h"
#include "Route.h"
#include "../requests/Request.h"
#include "map"

using namespace std;
using namespace Requests;

namespace Routes
{
    typedef string (*ControllerMethod)(Request);
    class Router
    {
    private:
        vector<Route *> routes;
        vector<string> params;
        map<string, ControllerMethod> mappedMethods;

        Router();
        void add(Route *route);
        void remove();
        Route *peek();
        bool isEmpty();
        void executeMethod(string alias);
    public:
        static Router *get();
        static vector<Route *> getAll();
        static void addRoute(string path, string methodAlias);
        static void mapMethod(string alias, ControllerMethod *method);
        static void setParams(char* params[]);
    };
}