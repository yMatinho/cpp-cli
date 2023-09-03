#pragma once
#include "string"
#include "iostream"
#include "stdio.h"

using namespace std;
namespace App
{
    namespace Input
    {
        class Input
        {
        private:
            Input()
            {
            }

        public:
            static Input *get();

            string getString(string label);

            int getInt(string label);
            float getFloat(string label);
            void anyKey(string label = "\n\nDigite qualquer tecla para voltar...");
            bool wishToContinue(string label = "\n\nDeseja continuar? Y[es] N[o] \n\n");
        };
    }
}