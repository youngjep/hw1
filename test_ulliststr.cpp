#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

using namespace std;

int main(int argc, char* argv[])
{
    ULListStr dat;
    for (int i =0 ; i < 50; i++)
        dat.push_back(to_string(i));

    //cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    //dat.pop_front();
    // prints: 8 7 9
    //cout << "back: " << dat.back() << endl;
    //cout << "index 1: " << dat.get(1) << endl;

    for (int i =0 ; i < 50; i++)
        dat.get(i);

    //cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
