#include "iostream"
#include "app/commands/StartProgram.h"
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
int main(int argc, char *argv[]) {
    Commands::StartProgram::start(argv);

    return 1;
}