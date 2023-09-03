#include "CalculateAverageView.h"
#include "iostream"
#include "string"

using namespace Views;

CalculateAverageView::CalculateAverageView() {}

void CalculateAverageView::render(map<string, any> *params, map<string, any *> *modifiablePointers)
{
     std::cout << "Oi, chegou a hora!\n\n";

    cout << "Oi, chegou a hora!\n\n" << "Sua média é: " << std::any_cast<float>((*params)["average"]);
}