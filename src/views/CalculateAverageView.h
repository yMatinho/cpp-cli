#pragma once
#include "View.h"
#include "map"
#include "any"
#include "string"
#include "vector"

using namespace std;

namespace Views
{
    class CalculateAverageView : public View
    {
    public:
        CalculateAverageView();

        void render(Requests::ViewRequest* viewRequest=nullptr) override;
        void inputGrades(Requests::ViewRequest* viewRequest=nullptr);
    };
}