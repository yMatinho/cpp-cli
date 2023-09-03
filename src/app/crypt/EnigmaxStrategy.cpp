#include "EnigmaxStrategy.h"
#include "cstring"
#include "string"
#include "cmath"
using namespace std;

bool isPontuactionSignal(char character) {
    return (character == ' ' || character == '!' || character == ',' || character == '.');
}

string EnigmaxStrategy::execute(string input)
{
    char* characters = new char[input.length() + 1];
    strcpy(characters, input.c_str());
    const int maxIndex = this->alphabet.length() - 1;
    string encryptedString;

    for(int i = 0; i < input.length(); i++) {
        char currentChar = input[i];

        size_t foundIndex = this->alphabet.find(currentChar);
        if(isPontuactionSignal(currentChar) || !foundIndex) {
            encryptedString.append(1, currentChar);
            continue;
        }
        int targetIndex = foundIndex + this->key;
        if(targetIndex > maxIndex) {
            int howManyOver = floor(targetIndex / maxIndex);
            targetIndex-= howManyOver * maxIndex;
        }
        encryptedString.append(1, this->alphabet.at(targetIndex));
    }

    return encryptedString;
}