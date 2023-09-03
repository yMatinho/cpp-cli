#include "HelloWorldController.h"
#include "../../routes/Router.h"
#include "../../views/HelloWorldView.h"

using namespace App::Controllers;
using namespace Views;

void HelloWorldController::hello(Request req)
{
    HelloWorldView* view = new HelloWorldView();
    view->render();
}