#include <iostream> 
#include <vector> 
#include "VoterCandidate.h" 

using namespace std;

vector<vector<string>> VoterCandidate::
getNamesAndScores(vector<string> voter, vector<vector<string>> candidates)
    {
        vector<vector<string>> nameScores;

        for(int i = 0; i < candidates.size(); i++)
        {
            nameScores.push_back(compareVoterAndCandidate(voter,candidates[i]));
        }
        return nameScores; 
    }

vector<string> VoterCandidate::
compareVoterAndCandidate(vector<string> voter, vector<string> candidate) 
    {
        vector<string> nameScore; 
        int score = 0;
        for(int i = 1; i < candidate.size(); i++)
        {
            if(voter[i].compare("0")==0 || candidate[i].compare("0")==0)
            {
                continue;
            }
            else if (voter[i].compare(candidate[i])==0)
            {
                score += 1;
            }
            else 
            {
                score -= 1; 
            }   
        }
        nameScore.push_back(candidate[0]);
        nameScore.push_back(to_string(score));
        return nameScore;
    }
 
 int VoterCandidate::findHighestScore(vector<vector<string>> nameScores)
    {
        int highestScore =  atoi(nameScores[0][1].c_str());
        
        for(int i = 1; i < nameScores.size(); i++)
        {
            int score = atoi(nameScores[i][1].c_str());
            if(highestScore < score)
            {
                highestScore = score; 
            } 
        }
        return highestScore; 
    }
    
vector<string> VoterCandidate::
getCandidatesWithHishestScore(vector<vector<string>> nameScores,int highestScore)
    {
        vector<string> names; 
        for(int i = 0; i < nameScores.size(); i++)
        {
            int score = atoi(nameScores[i][1].c_str());
            if(highestScore == score)
            {
                names.push_back(nameScores[i][0]);
            }
        }
        return names; 
    }