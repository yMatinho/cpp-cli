#include "HelloWorldView.h"
#include "iostream"

using namespace Views;

HelloWorldView::HelloWorldView() {}

void HelloWorldView::render(map<string, any> *params, map<string, any> *modifiablePointers)
{
    cout << "\n\n\nHello world again!\n\n\n";
}