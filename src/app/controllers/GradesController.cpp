#include "GradesController.h"
#include "../../routes/Router.h"
#include "../../views/CalculateAverageView.h"
#include "map"
#include "../../requests/ViewRequest.h"
#include "any"

using namespace App::Controllers;
using namespace Views;
using namespace Requests;

void GradesController::calculateAverage(Request req)
{
    float gradeSum = 0;
    for (int i = 1; i < req.getParamCount(); i++)
        gradeSum += ::atof(req.getParam(i).c_str());

    ViewRequest *viewRequest = new ViewRequest({{"average", gradeSum / (req.getParamCount() - 1)}});
    return (new CalculateAverageView())->render(viewRequest);
}

void GradesController::calculateAverageUsingInputs(Request req)
{
    ViewRequest *viewRequest = new ViewRequest({}, {{"grades", {}}});
    (new CalculateAverageView())->inputGrades(viewRequest);
    viewRequest->setParam<float>(
        "average",
        this->getAverage(viewRequest->getModifiable<vector<float>>("grades")));
    (new CalculateAverageView())->render(viewRequest);
}

float GradesController::getAverage(vector<float> grades)
{
    float gradeSum = 0;
    for (int i = 0; i < grades.size(); i++)
        gradeSum += grades[i];
    return gradeSum / grades.size();
}