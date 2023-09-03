#pragma once
#include "vector"
#include "string"

using namespace std;

namespace Requests
{
    class Request
    {
    protected:
        vector<string> params;

    public:
        Request(vector<string> params);

        string getParam(int index);
        int getParamCount();
    };
}