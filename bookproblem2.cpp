// bookproblem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>


using namespace std;

int main()
{
	bool flag = true;
	string name = "", rank = "", girlname = "", boyname = "", outMessage1 = "0", outMessage2 = "0";
	cout << "Enter the name to search for: ";
	cin >> name;
	std::transform(name.begin(), name.end(), name.begin(), tolower);
	//cout << "Name: " << name;

	ifstream infile("namesFile.txt");
	
		while (!infile.eof())
		{

			//getting new inputs
			boyname = "", rank = "", girlname = "";
			infile >> rank >> boyname >> girlname;

			//to lower all letters
			std::transform(boyname.begin(), boyname.end(), boyname.begin(), tolower);
			std::transform(girlname.begin(), girlname.end(), girlname.begin(), tolower);

			if (name == boyname)
			{
				outMessage1 = "0";
				outMessage1 = "The Rank of name "; ;
				outMessage1 += boyname;
				outMessage1 += " in boys is: ";
				outMessage1 += rank;
			}
			if (name == girlname)
			{
				outMessage2 = "0";
				outMessage2 = "The Rank of name ";
				outMessage2 += girlname;
				outMessage2 += " in girls is: ";
				outMessage2 += rank;
			}

		}
		
		if (outMessage1 == "0" && outMessage2 == "0") 
		{
			cout << "The name is not found." << endl;
		}
		
		else if (outMessage1 == "0" && outMessage2 != "0") 
		{
			cout <<endl<< "The name is not found in boys names. " << endl;
			cout << endl << outMessage2 << endl;
		}
		
		else if (outMessage1 != "0" && outMessage2 == "0") 
		{
			cout << endl << outMessage1 << endl;
			cout << "The name is not found in girls names. " << endl;
		}
		
		else if (outMessage1 != "0" && outMessage2 != "0") {
			cout << endl << outMessage1 << endl;
			cout << outMessage2 << endl;
		}
	


		/*cout << "rank: " << rank << endl;
		cout << "boyname: " << boyname << endl;
		cout << "girlname: " << girlname << endl;*/
	infile.close();

		return 0;
}

