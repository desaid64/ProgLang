import java.util.*; 
public class VoterCandidate
{
    public VoterCandidate()
    {
    }

    public List<List<String>> getNamesAndScores(List<String> voter, List<List<String>> candidates)
    {
        List<List<String>> nameScores = new ArrayList<List<String>>();

        for(int i = 0; i < candidates.size(); i++)
        {
            nameScores.add(compareVoterAndCandidate(voter,candidates.get(i)));
        }
        return nameScores; 
    }

    private List<String> compareVoterAndCandidate(List<String> voter, List<String> candidate) 
    {
        List<String> nameScore = new ArrayList<String>(); 
        int score = 0;
        for(int i = 1; i < candidate.size(); i++)
        {
            if(voter.get(i).equals("0") || candidate.get(i).equals("0"))
            {
                continue;
            }
            else if (voter.get(i).equals(candidate.get(i)))
            {
                score += 1;
            }
            else 
            {
                score -= 1; 
            }   
        }
        nameScore.add(candidate.get(0));
        nameScore.add(String.valueOf(score));
        return nameScore;
    }
    
    public int findHighestScore(List<List<String>> nameScores)
    {
        int highestScore = Integer.parseInt(nameScores.get(0).get(1)); 
        for(int i = 1; i < nameScores.size(); i++)
        {
            int score = Integer.parseInt(nameScores.get(i).get(1));
            if(highestScore < score)
            {
                highestScore = score; 
            } 
        }
        return highestScore; 
    }
    
    public List<String> getCandidatesWithHishestScore(List<List<String>> nameScores,int highestScore)
    {
        List<String> names = new ArrayList<String>(); 
        for(int i = 0; i < nameScores.size(); i++)
        {
            int score = Integer.parseInt(nameScores.get(i).get(1));
            if(highestScore == score)
            {
                names.add(nameScores.get(i).get(0));
            }
        }
        return names; 
    }
}