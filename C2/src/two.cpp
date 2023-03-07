#include <iostream>
#include <string>

using namespace std;

void twenty_one(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j;
	cout << endl << "Enter elements of matrix 1:" << endl;
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnFirst; ++j)
		{
			cout << "Enter elements a"<< i + 1 << j + 1 << ": ";
			cin >> firstMatrix[i][j];
		}
	}

	cout << endl << "Enter elements of matrix 2:" << endl;
	for(i = 0; i < rowSecond; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			cout << "Enter elements b" << i + 1 << j + 1 << ": ";
			cin >> secondMatrix[i][j];
		}
	}
}

void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int mult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			for(k=0; k<columnFirst; ++k)
			{
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

int main() {
    // The password is hidden as an array of characters
    char var1[] = {'\x71', '\x7a', '\x67', '\x6a', '\x78', '\x64', '\x6d', '\x76', '\x6b', '\x6f', '\x6a', '\x6d', '\x00'};

    // Prompt the user to enter the password
    cout << "Please enter the password: ";
    string input;
    cin >> input;

    // Convert the user's input to a character array
    char input_chars[input.length() + 1];
    strcpy(input_chars, input.c_str());

    // Check if the input matches the password
    if (strcmp(input_chars, var1) == 0) {
        cout << "Correct password. Access granted." << endl;
    } else {
        cout << "Incorrect password. Access denied." << endl;
    }

    return 0;
}
