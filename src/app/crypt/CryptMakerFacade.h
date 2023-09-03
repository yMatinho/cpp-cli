#pragma once
#include "TextCryptStrategy.h"
#include "string"

using namespace std;

class CryptMakerFacade {
    private:
    TextCryptStrategy* strategy;
    public:
    CryptMakerFacade(TextCryptStrategy* strategy);

    string encrypt(string text);
};