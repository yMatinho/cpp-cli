#pragma once
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
        float getAverage(vector<float> grades);
        public:
            GradesController() : Controller() {}
            void calculateAverage(Request req);
            void calculateAverageUsingInputs(Request req);
        };
    }
}