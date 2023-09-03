#include "string"
#include "algorithm"
#include "random"

using namespace std;

namespace Facades
{

    class StringFacade
    {
    public:
        string generateRandom(int len)
        {
            static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
            std::string tmp_s;
            tmp_s.reserve(len);

            for (int i = 0; i < len; ++i)
            {
                tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
            }

            return tmp_s;
        }
        string randomizeString(string inputString)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::shuffle(inputString.begin(), inputString.end(), gen);

            return inputString;
        }
    };
}