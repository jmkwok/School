#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

bool validation(char c) //True/False Function
{
	if(toupper(c) >= 'A' && toupper(c) <= 'Z') // Check it it has letters
		{
			return true;
		}

	else if (c >= '0' && c <= '9') // Check if it has numbesr
		{
			return true;
		}

	else if (c == '_' || c == '-' || c == '.' || c == '+' || c == '@') // Check for specific characters
		{
			return true;
		}
	
	else
		{
			return false;
		}
}


int main()
{
	string userInput; // User Input
	string inputFile;
	string defaultInput = "filecontainingEmails.txt"; // Default
	
	string userOutput; //User Output
	string outputFile;
	string defaultOutput = "copyPasteMyEmails.txt"; //Default

	//User put in Input	
	cout << "Enter input filename [default: " << defaultInput << "]: ";
	getline(cin, userInput);
	
	if (userInput == "")
		{
			inputFile = defaultInput; // Enter --> Default Input
		}
		
	else
		{
			inputFile = userInput; // Input --> User Input
			defaultOutput = userInput; //User input --> Default Output
		}
	
	//User put in Output		
	cout << "Enter output filename [default: " << defaultOutput << "]: ";
	getline(cin, userOutput);
	
	if (userOutput == "")
		{
			outputFile = defaultOutput; //If Enter --> Default
		}
	
	else
		{
			outputFile = userOutput; // Else it will be User Output
		}
	
	cout << endl;
	
	
	//Echo Lines
	cout << "Input file: " << inputFile << endl;
	cout << "Output file: " << outputFile << endl;
	
	//Begin reading text files
	ifstream fin;
   	fin.open(inputFile.c_str());
    if(!fin.good()) throw "I/O error"; // Place error check 
	
	
	//Read length of lines in file
	string readFile;
	
	while(fin.good())
    {
        getline(fin, readFile);
        for(int i = 0; i < readFile.size() ;i++ ) // Read file lines
        {
            if (readFile.at(i) == '@') // Looking for @ in email names
				{
					int s, e, hasDot;
					
					for(s=i; validation(readFile.at(s)); s--); // Start validation
					for(e=i; validation(readFile.at(e)); e++); // End validation
					
					if (readFile.at(e) == '.') // End looking for '.'
						{
							hasDot++;
						}
					
					if (readFile.at(e) >= 1) // Print line when @ is found but pull as substing
						{
							cout << readFile.substr(s+1, e-s-1) << endl;
						}
					
             	} // End of Line Check

        } // End for - read file

    }// End while    
	
	
}