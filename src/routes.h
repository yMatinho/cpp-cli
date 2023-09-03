#include "routes/Router.h"
#include "app/controllers/GradesController.h"
#include "app/controllers/HelloWorldController.h"

using namespace Routes;
using namespace App::Controllers;

void routes()
{
    Router::get()->addRoute<HelloWorldController>("", &App::Controllers::HelloWorldController::hello);
    Router::get()->addRoute<GradesController>("grade-average", &App::Controllers::GradesController::calculateAverage);
}