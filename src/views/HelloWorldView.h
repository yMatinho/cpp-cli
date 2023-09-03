#pragma once
#include "View.h"
#include "map"
#include "any"
#include "string"

using namespace std;

namespace Views
{
    class HelloWorldView : public View
    {
    public:
        HelloWorldView();

        void render(map<string, any> *params = nullptr, map<string, any> *modifiablePointers = nullptr) override;
    };
}