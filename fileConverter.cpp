#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string ConvertToDelimiter(const string &str, char delimiter, char newDelimiter)
{
    string output = str;
    for (int i = 0, size = output.length(); i < size; i++)
    {
        if (output[i] == delimiter)
        {
            output[i] = newDelimiter;
        }
    }
    return output;
}

int main(int argc, char *argv[])
{
    // input tsvConverter (-t|-c) {filename} {outputfileName}
    if (argc < 4 || argc > 4)
    {
        cout << "Please use the expected amount of arguments. tsvConverter (-t|-c) {filename} {outputfileName}";
    }
    string argv1 = argv[1];
    if (!(argv1 == "-t" || argv1 == "-c"))
    {
        cout << "Unexpected argument supplied" << "\"" << argv1 << "\"" << ". Please use either -c or -t to specify if the output should be csv or tsv";
    }
    std::ifstream input(argv[2], std::ios::binary);
    if (input.fail() || input.bad())
    {
        cout << "Please enter in a valid file to read from";
    }
    std::ofstream output(argv[3], std::ios::binary);
    if (output.fail() || output.bad()) {
        cout << "Please enter in a valid file to output to";
    }
    string line;
    int count = 0;
    getline(input, line);
    while (input)
    {
        if (argv1 == "-t")
        {
            output << ConvertToDelimiter(line, ',', '\t');
        }
        else
        {
            output << ConvertToDelimiter(line, '\t', ',');
        }
        getline(input, line);
        count++;
    }
    cout << endl << "Lines processed: " << count << endl;
}