#include "StartProgram.h"
#include "../exceptions/Exception.h"
#include "../exceptions/BreakException.h"
#include <iostream>
#include "string"
#include "../../routes/Router.h"

using namespace std;
using namespace Exceptions;
using namespace Commands;
using namespace Routes;

void StartProgram::start(int argc, char *argv[])
{
    try
    {
        Router::get()->setParams(argv);
        Router::get()->executeRoute();
    }
    catch (BreakException *e)
    {
        cout << "Saindo..." << "\n\n";
    }
    catch (Exception *e)
    {
        cout << e->getMessage() << "\n\n";
    }
}