#pragma once
#include "../../requests/Request.h"
#include "Controller.h"

using namespace Requests;

namespace App
{
    namespace Controllers
    {
        class HelloWorldController : public Controller
        {
        private:
        public:
            HelloWorldController() : Controller() {}
            void hello(Request req);
        };
    }
}