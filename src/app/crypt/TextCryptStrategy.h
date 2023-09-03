#pragma once
#include "string"

using namespace std;

class TextCryptStrategy {
    protected:
    TextCryptStrategy();

    public:
    virtual string execute(string source);
};