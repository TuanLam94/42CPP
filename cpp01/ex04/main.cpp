#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Args error, launch like this : ./sed filename string1 string2\n";
		return (1);
	}

	std::string inputFile = argv[1];						//open input file
	std::ifstream input_stream(inputFile.c_str());			//c_str converts a string to an array of characters with a nullbyte at the end
	if (!input_stream.is_open()) {
		std::cerr << "Can't open" << inputFile << "\n";
		return (1);
	}

	std::string outputFile = inputFile + ".replace";		//open output file
	std::ofstream output_stream(outputFile.c_str());
	if (!output_stream.is_open()) {
		std::cerr << "Can't open" << outputFile << "\n";
		return (1);
	}

	std::string line;
	std::string toReplace = argv[2];
	std::string replacement = argv[3];

	while (std::getline(input_stream, line))				//reading input file line by line
    {
        std::string newLine;
        size_t pos = 0;
        size_t found;
        
        while ((found = line.find(toReplace, pos)) != std::string::npos)	//find toReplace position until the end of string 
        {
            newLine += line.substr(pos, found - pos);		//copy line to newline until start of toReplace
            newLine += replacement;							//adds replacement to newline
            pos = found + toReplace.length();				//update pos to after toReplace
        }
        newLine += line.substr(pos);							//after all replacements, copy end of line to newline
        
        output_stream << newLine << "\n";					//add newline to output file
    }

	output_stream.close();
	input_stream.close();
	return (0);
}