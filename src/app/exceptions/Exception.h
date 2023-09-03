#pragma once
#include "string"

using namespace std;

namespace Exceptions {
    class Exception {
        protected:
            string message;
        public:
            Exception(string message) {
                this->message = message;
            }
            string getMessage() {
                return this->message;
            }
    };
};