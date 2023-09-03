#include "Request.h"

using namespace Requests;

Request::Request(vector<string> params)
{
    this->params = params;
}

string Request::getParam(int index)
{
    return this->params.at(index);
}

int Request::getParamCount() {
    return this->params.size();
}