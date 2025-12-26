class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for (char c : customers)
            if (c == 'Y') totalY++;

        int penalty = totalY;
        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 1; i <=customers.size(); i++) {
            if (customers[i-1] == 'Y')
                penalty--;
            else
                penalty++;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i ;
            }
        }

        return bestHour;
    }
};
