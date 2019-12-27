import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*; 

public class CSVReader
{
    private String fileName;
    private List<String> voter; 
    private List<List<String>> candidates;  
    public CSVReader()
    { 
        fileName = ""; 
        voter = new ArrayList<String>(); 
        candidates = new ArrayList<List<String>>();
    }

    public void setFileName(String fileName)
    {
        this.fileName = fileName; 
    }

    public String getFileName()
    {
        return fileName; 
    } 

    public void readFile(String fileName)
    { 
        String line = ""; 
        String csvSplitBy= ","; 
        int counter = 0; 
        try(BufferedReader br = new BufferedReader(new FileReader(fileName)))
        {
            while((line = br.readLine()) != null)
            {
                String[] values =  line.split(csvSplitBy);
                if(counter == 0)
                {
                    voter = Arrays.asList(values);
                }
                else 
                {
                    candidates.add(Arrays.asList(values));
                }
                counter++;
                
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public List<String> getVoter()
    {
        return voter;
    }

    public List<List<String>> getCandidates()
    {
        return candidates;
    }
}