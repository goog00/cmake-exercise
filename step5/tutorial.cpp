
#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif
 

int main(int argc, char *argv[])
{

    if (argc < 2)
    {

        std::cout << argv[0] << " version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "usage: " << argv[0] << "  number " << std::endl;

        return 1;
    }

    const double inputValue = std::stod(argv[1]);

    // const double outputValue = mysqrt(inputValue);

#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif



    std::cout << "the square root of " << inputValue
              << " is " << outputValue
              << std::endl;

    return 0;
}