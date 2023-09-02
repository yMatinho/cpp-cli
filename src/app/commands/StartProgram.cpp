#include "StartProgram.h"
#include "../exceptions/Exception.h"
#include "../exceptions/BreakException.h"
#include <iostream>
#include "string"

using namespace std;
using namespace Exceptions;
using namespace Commands;

void StartProgram::start(char *args[])
{
    try
    {
        cout << "Hello world!";
    }
    catch (BreakException *e)
    {
        cout << "Saindo...";
    }
    catch (Exception *e)
    {
        cout << e->getMessage();
    }
}