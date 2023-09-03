#pragma once
#include "TextCryptStrategy.h"
#include "string"

using namespace std;

class EnigmaxStrategy : public TextCryptStrategy
{
private:
    int key;
    string alphabet;

public:
    EnigmaxStrategy(string alphabet, int key = 13)
    {
        this->alphabet = alphabet;
        this->key = key;
    }

    string execute(string input);
};