#include "string"

using namespace std;

namespace Routes
{
    class Route
    {
    private:
        string path;
    public:
        Route(string path);

        string getPath();
    };
}