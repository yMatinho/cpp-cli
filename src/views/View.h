#pragma once
#include "map"
#include "any"
#include "string"

using namespace std;

namespace Views
{
    class View
    {
    public:
        virtual void render(map<string, any> *params = nullptr, map<string, any *> *modifiablePointers = nullptr) = 0;
    };
}