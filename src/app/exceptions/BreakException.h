#pragma once
#include "string"
#include "Exception.h"

using namespace std;

namespace Exceptions {
    class BreakException : public Exception {
        public:
            BreakException(string message) : Exception(message) {
            }
    };
};