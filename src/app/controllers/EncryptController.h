#pragma once
#include "../../requests/Request.h"
#include "Controller.h"

using namespace Requests;

namespace App
{
    namespace Controllers
    {
        class EncryptController : public Controller
        {
        private:
        public:
            EncryptController() : Controller() {}
            void encrypt(Request req);
        };
    }
}