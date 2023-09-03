#include "EncryptController.h"
#include "../../routes/Router.h"
#include "../../views/HelloWorldView.h"
#include "../crypt/TextCryptStrategy.h"
#include "../crypt/ROT13Strategy.h"
#include "../crypt/CryptMakerFacade.h"
#include "iostream"
#include "../facades/StringFacade.h"

using namespace App::Controllers;
using namespace Views;
using namespace std;

void EncryptController::encrypt(Request req)
{
    map<string, TextCryptStrategy *> strategies = {
        {"rot13", new ROT13Strategy()},
        {"enigmax", new ROT13Strategy()}};
    CryptMakerFacade *facade = new CryptMakerFacade(strategies[req.getParam(1)]);
    cout << "\n\n\n"
         << facade->encrypt(req.getParam(2)) << "\n\n\n";
}

void EncryptController::randomAlphabet(Request req)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    Facades::StringFacade* facade = new Facades::StringFacade();
    cout << "\n\n" << facade->randomizeString(alphabet) << "\n\n";
}