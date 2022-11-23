// Utilities.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdlib.h>

#include "Lib/StopwatchService.h";

int main()
{
    stopwatchService.startWatch("THIS IS A TEST");


    //DO Stuff
    std::cin.ignore(); // a pause for a user defined time to test stopwatch


    stopwatchService.endWatch("THIS IS A TEST");

}