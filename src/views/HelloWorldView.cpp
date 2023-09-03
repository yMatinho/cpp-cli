#include "HelloWorldView.h"
#include "iostream"

using namespace Views;

HelloWorldView::HelloWorldView() {}

void HelloWorldView::render(Requests::ViewRequest* viewRequest)
{
    cout << "\n\n\nHello world again!\n\n\n";
}