#pragma once
#include "map"
#include "string"
#include "any"
#include "../app/exceptions/Exception.h"

using namespace std;

namespace Requests
{
    class ViewRequest
    {
    private:
        map<string, any> params;
        map<string, any> modifiable;

    public:
        ViewRequest(map<string, any> params = {}, map<string, any> modifiable = {})
        {
            this->params = params;
            this->modifiable = modifiable;
        }

        template <typename T>
        T getParam(string key)
        {
            return any_cast<T>((this->params)[key]);
        }

        template <typename T>
        void setParam(string key, T value)
        {
            const bool paramExists = this->params.find(key) == this->params.end();
            if (!paramExists)
                throw new Exceptions::Exception("Param doesn't exists");
            (this->params)[key] = (any)value;
        }

        template <typename T>
        T getModifiable(string key)
        {
            const bool modifiableExists = this->modifiable.find(key) != this->modifiable.end();
            if (!modifiableExists)
                throw new Exceptions::Exception("Modifiable doesn't exists");
            return any_cast<T>((this->modifiable)[key]);
        }

        template <typename T>
        void setModifiable(string key, T value)
        {
            (this->modifiable)[key] = (any)value;
        }
    };
}