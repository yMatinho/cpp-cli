#include "routes/Router.h"
#include "app/controllers/GradesController.h"
#include "app/controllers/HelloWorldController.h"
#include "app/controllers/EncryptController.h"

using namespace Routes;
using namespace App::Controllers;

void routes()
{
    Router::get()->addRoute<HelloWorldController>("", &App::Controllers::HelloWorldController::hello);

    Router::get()->addRoute<GradesController>("grade-average", &App::Controllers::GradesController::calculateAverage);
    Router::get()->addRoute<GradesController>("grade-average-input",
                                              &App::Controllers::GradesController::calculateAverageUsingInputs);

    Router::get()->addRoute<EncryptController>("encrypt/rot13", &App::Controllers::EncryptController::encryptRot13);
    Router::get()->addRoute<EncryptController>("encrypt/enigmax", &App::Controllers::EncryptController::encryptEnigmax);
    Router::get()->addRoute<EncryptController>("random-alphabet", &App::Controllers::EncryptController::randomAlphabet);
}