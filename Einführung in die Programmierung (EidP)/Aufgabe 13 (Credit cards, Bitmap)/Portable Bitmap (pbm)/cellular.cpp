// recreated 08.07.2019
#include <iostream>
#include <fstream>
#include <string>
#include "PortableBitmap.h"

using namespace std;

bool transitionFunction(bool left, bool center, bool right);

int main()
{
    char const characterMap[] = { '_', '#' };
    int const maxGenerations = 150;
    int const cellCount = 100;
    bool universe[cellCount] = { 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
    bool tempUniverse[cellCount] = { 0 };
	ofstream file;
	file.open("cellular.txt");
    for (int i = 0; i < maxGenerations; ++i) {
        // output
        for (int j = 0; j < cellCount; ++j) {
            cout << characterMap[universe[j]];
			if(file.is_open())
				file << characterMap[universe[j]];
        }
        cout << endl;
		if (file.is_open())
			file << endl;
        // update
        tempUniverse[0] = transitionFunction(universe[cellCount - 1], universe[0], universe[1]);
        for (int j = 1; j < cellCount - 1; ++j) {
            tempUniverse[j] = transitionFunction(universe[j - 1], universe[j], universe[j + 1]);
        }
        tempUniverse[cellCount - 1] = transitionFunction(universe[cellCount - 2], universe[cellCount - 1], universe[0]);
        // copy
        for (int j = 0; j < cellCount; ++j) {
            universe[j] = tempUniverse[j];
        }
    }
	file.close();
	try {
		PortableBitmap pbm("cellular.txt", '_', '#');
		pbm.save("cellular");
	}
	catch (PBMException& e) {
		cout << e.getMessage() << endl;
	}

    return 0;
}

bool transitionFunction(bool left, bool center, bool right)
{
    static bool const transitionMap[] = { 0, 1, 1, 1, 0, 1, 1, 0 };

    int inputEncoded = right + 2 * center + 4 * left;
    return transitionMap[inputEncoded];
}

