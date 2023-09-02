#include "GradesController.h"
#include "../../routes/Router.h"
#include "../../views/HelloWorldView.h"

using namespace App::Controllers;
using namespace Views;

void GradesController::calculateAverage(Request req)
{
    HelloWorldView* view = new HelloWorldView();
    view->render();
}