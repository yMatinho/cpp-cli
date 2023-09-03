#include "Input.h"

using namespace App::Input;

Input *Input::get()
{
    static Input *instance = new Input();
    return instance;
}

string Input::getString(string label)
{
    cout << label;
    string input;
    getline(std::cin >> std::ws, input);
    return input;
}

int Input::getInt(string label)
{
    cout << label;
    int input;
    cin >> input;
    return input;
}
float Input::getFloat(string label)
{
    cout << label;
    float input;
    cin >> input;
    return input;
}
void Input::anyKey(string label)
{
    cout << label;
    cin.ignore();
    cin.ignore();
}
bool Input::wishToContinue(string label)
{
    cout << label;
    char wishToContinue;
    cin >> wishToContinue;
    if (wishToContinue == 'N')
        return false;
    return true;
}