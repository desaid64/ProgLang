#include <iostream>
#include "CSVReader.h"
#include "VoterCandidate.h" 
using namespace std;

int main()
{
    CSVReader reader; 
    reader.readFile("../Input/input3.csv");

    VoterCandidate vc; 
    vector<vector<string>> nameScores = vc.getNamesAndScores(reader.getVoter(), reader.getCandidates());
    int highestScore = vc.findHighestScore(nameScores);
    vector<string> bestCandidates = vc.getCandidatesWithHishestScore(nameScores, highestScore);
    reader.print1DVector(bestCandidates);

    return 0;
}
