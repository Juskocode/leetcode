class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        //only can create groups if the size is divisible
        if (n % groupSize != 0)
            return false;
        //bucket count prep
        unordered_map<int, int> cardCount;
        for (const auto & card : hand)
            cardCount[card]++;
        
        for (const auto & card : hand)
        {
            int start = card;
            //find potential start candidate
            while (cardCount[start - 1])
                start--;
            
            //process candidate and sequence
            while (start <= card)
            {
                while (cardCount[start]) //for dup cards
                {
                    //check if the start is fisable
                    for (int nextc = start; nextc < start + groupSize; nextc++)
                    {
                        if (!cardCount[nextc])
                            return false;
                        cardCount[nextc]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};