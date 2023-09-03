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

        void render(map<string, any> *params = nullptr, map<string, any> *modifiablePointers = nullptr) override;
        void inputGrades(map<string, any> *params = nullptr, map<string, any> *modifiablePointers = nullptr);
    };
}