#include "CalculateAverageView.h"
#include "iostream"
#include "string"

using namespace Views;

CalculateAverageView::CalculateAverageView() {}

void CalculateAverageView::render(map<string, any> *params, map<string, any *> *modifiablePointers)
{
    cout << "Oi, chegou a hora!\n\n" << "Sua média é: " << std::any_cast<float>((*params)["average"]);
}