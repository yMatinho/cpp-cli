#include "CalculateAverageView.h"
#include "iostream"
#include "../app/input/Input.h"
#include "string"

using namespace Views;
using namespace App::Input;

CalculateAverageView::CalculateAverageView() {}

void CalculateAverageView::render(Requests::ViewRequest *viewRequest)
{
    cout << "Oi, chegou a hora!\n\n"
         << "Sua média é: " << viewRequest->getParam<float>("average") << "\n\n";
}

void CalculateAverageView::inputGrades(Requests::ViewRequest *viewRequest)
{
    cout << "#TÁNAHORATÁNAHORA" << "\n\n";
    vector<float> grades = {};
    for (;;)
    {
        grades.push_back(Input::get()->getFloat("\n\nDigite sua nota: "));
        if (!Input::get()->wishToContinue())
            break;
    }
    viewRequest->setModifiable<vector<float>>("grades", grades);
}