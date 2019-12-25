import csv

fileName = '../Input/input3.csv'

def readInput(fileName):
    with open(fileName, 'r') as csvfile:
        readCSV = csv.reader(csvfile,delimiter=',')
        rows = []
        for row in readCSV:
            rows.append(row)
    return rows[0],rows[1:]


def calculateNamesAndScores(voter,Candidates):
    nameScores = []
    for candidate in Candidates:
        nameScores.append(compareVotes(voter,candidate))
    return nameScores

def compareVotes(voter,candidate):
    name = candidate[0]
    score = 0
    for i in range(1,len(voter)):
        if voter[i] == '0' or candidate[i] == '0':
            continue
        elif voter[i] == candidate[i]:
            score += 1
        else:
            score -= 1
    return name,score

def findHighestScore(nameScores):
    highestScore = nameScores[0][1] 
    for i in range(1,len(nameScores)): 
        if highestScore < nameScores[i][1]:
            highestScore = nameScores[i][1]
    return highestScore

def getCandidatesWithHishestScore(nameScores,highestScore):
    bestCandidates = []
    for name,score in nameScores:
        if score == highestScore:
            bestCandidates.append(name)
    return bestCandidates

def main(): 
    voter,candidates = readInput(fileName) 
    nameScores = calculateNamesAndScores(voter,candidates)    
    score = findHighestScore(nameScores)
    candidatesWithHighestScore = getCandidatesWithHishestScore(nameScores,score)
    print(candidatesWithHighestScore)
if __name__ == "__main__":
    main()
   