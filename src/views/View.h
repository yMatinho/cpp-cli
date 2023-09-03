#pragma once
#include "map"
#include "any"
#include "string"
#include "../requests/ViewRequest.h"
using namespace std;

namespace Views
{
    class View
    {
    public:
        virtual void render(Requests::ViewRequest* viewRequest=nullptr) = 0;
    };
}