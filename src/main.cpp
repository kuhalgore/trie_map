#include <iostream>
#include<exception>

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char *argv[])
{
    std::string inputFile{};
    size_t noofThreads = 0;
    if (argc == 1)
    {
        std::cout << "Running unit tests using Catch2 framework\n";
        try
        {
            //run all unit test cases using catch2 unit testing framework 
            auto result = Catch::Session().run(argc, argv);
            return result;
        }
        catch (...)
        {
            return -1;
        }
    }
	else
	{
		std::cout<<"\nThe program does not support any arguments passed";
	}	
    
    return 0;
}