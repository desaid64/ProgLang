import java.util.*; 

public class Driver
{
    public static void main(String[] args)  
    {
        CSVReader reader = new CSVReader();
        reader.readFile("/home/deep/ProgLang/ProgLangChallenge/Input/input2.csv");
        
        VoterCandidate vc = new VoterCandidate();
        List<List<String>> nameScores  = vc.getNamesAndScores(reader.getVoter(), reader.getCandidates());
        int highestScore = vc.findHighestScore(nameScores);
        List<String> bestCandidates = vc.getCandidatesWithHishestScore(nameScores, highestScore);
        System.out.println(bestCandidates);
    }
}