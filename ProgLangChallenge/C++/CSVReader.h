#include <iostream> 
#include <vector> 
using namespace std; 
class CSVReader 
{
    
    public: 
    void readFile(string fileName);

    vector<string> getVoter()
    {
        return voter;
    }
    
    vector<vector<string>>getCandidates()
    {
        return candidates;
    }
    void print1DVector(vector<string> array);
    void print2DVector(vector<vector<string>> array2d);

    private: 
    vector<vector<string>> candidates;
    vector<string> voter; 
    
};