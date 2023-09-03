#include "CryptMakerFacade.h"

CryptMakerFacade::CryptMakerFacade(TextCryptStrategy *strategy)
{
    this->strategy = strategy;
}

string CryptMakerFacade::encrypt(string text)
{
    return this->strategy->execute(text);
}