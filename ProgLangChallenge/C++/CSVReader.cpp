#include "CSVReader.h"
#include <iostream> 
#include <vector> 
#include <sstream>
#include <fstream>

using namespace std; 

void CSVReader::readFile(string fileName)
{
    ifstream  data(fileName);
    string line;
    int counter = 0; 
    while(getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }
        if(counter == 0)
        {
            voter = parsedRow;
        }
        else
        { 
            candidates.push_back(parsedRow);
        }
        counter++;
        
    }
}

void CSVReader::print1DVector(vector<string> array)
{
    for(int i = 0; i < array.size(); i++)
    {
        cout << array.at(i) << " ";
    }
    cout << endl; 
}

void CSVReader::print2DVector(vector<vector<string>> array2d)
{
    for (int i = 0; i < array2d.size(); i++)
    {
        print1DVector(array2d[i]);
    }   
}



