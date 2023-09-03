#include "routes/Router.h"
#include "app/controllers/GradesController.h"

using namespace Routes;
using namespace App::Controllers;

void routes()
{
    Router::get()->addRoute<GradesController>("teste",
                                              &App::Controllers::GradesController::calculateAverage);
}