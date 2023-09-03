#include "CalculateAverageView.h"
#include "iostream"
#include "../app/input/Input.h"
#include "string"

using namespace Views;
using namespace App::Input;

CalculateAverageView::CalculateAverageView() {}

void CalculateAverageView::render(map<string, any> *params, map<string, any> *modifiablePointers)
{
    cout << "Oi, chegou a hora!\n\n"
         << "Sua média é: " << std::any_cast<float>((*params)["average"]) << "\n\n";
}

void CalculateAverageView::inputGrades(map<string, any> *params, map<string, any> *modifiablePointers)
{
    cout << "#TÁNAHORATÁNAHORA"
         << "\n\n";
    vector<float> grades = {};
    for (;;)
    {
        float grade = Input::get()->getFloat("\n\nDigite sua nota: ");
        grades.push_back(grade);
        if (!Input::get()->wishToContinue())
            break;
    }
    (*modifiablePointers)["grades"] = (any)grades;
}