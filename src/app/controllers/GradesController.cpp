#include "GradesController.h"
#include "../../routes/Router.h"
#include "../../views/CalculateAverageView.h"
#include "map"
#include "any"

using namespace App::Controllers;
using namespace Views;

void GradesController::calculateAverage(Request req)
{
    float gradeSum = 0;
    for (int i = 1; i < req.getParamCount(); i++)
        gradeSum += ::atof(req.getParam(i).c_str());
    map<string, any> viewParams = {{"average", gradeSum / (req.getParamCount() - 1)}};
    return (new CalculateAverageView())->render(&viewParams);
}

void GradesController::calculateAverageUsingInputs(Request req)
{
    map<string, any> viewParams = {};
    map<string, any> modifiablePointers = {{"grades", {}}};
    (new CalculateAverageView())->inputGrades(&viewParams, &modifiablePointers);
    viewParams["average"] = this->getAverage(any_cast<vector<float>>(modifiablePointers["grades"]));
    (new CalculateAverageView())->render(&viewParams);
}

float GradesController::getAverage(vector<float> grades)
{
    float gradeSum = 0;
    for (int i = 0; i < grades.size(); i++)
        gradeSum += grades[i];
    return gradeSum / grades.size();
}