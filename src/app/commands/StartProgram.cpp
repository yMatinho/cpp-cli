#include "StartProgram.h"
#include "../exceptions/Exception.h"
#include "../exceptions/BreakException.h"
#include <iostream>
#include "chrono"
#include "string"
#include "../../routes/Router.h"
#include "iomanip"

using namespace std;
using namespace Exceptions;
using namespace Commands;
using namespace Routes;

void StartProgram::start(int argc, char *argv[], bool executionTime)
{
    auto start = std::chrono::high_resolution_clock::now();

    try
    {

        Router::get()->setParams(argc, argv);
        Router::get()->executeRoute();
    }
    catch (BreakException *e)
    {
        cout << "Breaking the execution..."
             << "\n\n";
    }
    catch (Exception *e)
    {
        cout << e->getMessage() << "\n\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    if (executionTime)
        std::cout << "\n\n\nExecution time: " << fixed << setprecision(10) << (float)duration.count() / 1000000 << " milliseconds\n\n";
}