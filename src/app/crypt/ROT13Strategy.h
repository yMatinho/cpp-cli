#pragma once
#include "TextCryptStrategy.h"
#include "string"

using namespace std;

class ROT13Strategy : public TextCryptStrategy
{
    private:
    int key;
public:
    ROT13Strategy(int key=13);

    string execute(string input);
};