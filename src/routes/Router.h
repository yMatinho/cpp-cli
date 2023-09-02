#include "vector"
#include "string"
#include "Route.h"

using namespace std;

namespace Routes
{
    class Router
    {
    private:
        vector<Route*> routes;

        Router();
        void add(Route *route);
        void remove();
        Route* peek();
        bool isEmpty();
        static Router* get();

    public:
        static vector<Route*> getAll();
        static void addRoute(string path);
    };
}