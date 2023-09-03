#include "iostream"
#include "routes.h"
#include "app/commands/StartProgram.h"
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
int main(int argc, char *argv[]) {
    routes();
    Commands::StartProgram::start(argc, argv, true);

    return 1;
}