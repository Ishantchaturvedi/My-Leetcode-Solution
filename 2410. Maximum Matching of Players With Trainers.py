class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        i,j=0,0
        ans=0
        while i<len(players):
            while j<len(trainers) and trainers[j]<players[i]:
                j+=1
            if j==len(trainers):
                break
            i+=1
            j+=1
            ans+=1
        return ans