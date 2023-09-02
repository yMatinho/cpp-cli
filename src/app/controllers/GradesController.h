#include "../../requests/Request.h"
#include "Controller.h"

using namespace Requests;

namespace App
{
    namespace Controllers
    {
        class GradesController : public Controller
        {
        private:
        public:
            GradesController() : Controller() {}
            string calculateAverage(Request* req);
        };
    }
}