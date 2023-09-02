#include "routes/Router.h"
#include "app/controllers/GradesController.h"

using namespace Routes;
using namespace App::Controllers;

void routes()
{
    Router::get()->addRoute<GradesController>("crypt rot13",
                                              "GradesController@calculateAverage",
                                              &App::Controllers::GradesController::calculateAverage);
}