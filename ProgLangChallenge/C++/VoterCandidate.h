#include <iostream> 
#include <vector> 
using namespace std; 
class VoterCandidate 
{
    
    public: 
    vector<vector<string>> getNamesAndScores(vector<string> voter, vector<vector<string>> candidates);
    int findHighestScore(vector<vector<string>> nameScores);
    vector<string> getCandidatesWithHishestScore(vector<vector<string>> nameScores,int highestScore);

    private:
    vector<string> compareVoterAndCandidate(vector<string> voter, vector<string> candidate) ;
            
};