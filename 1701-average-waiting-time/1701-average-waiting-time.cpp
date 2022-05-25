class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0, currTime = customers[0][0];
        for(vector<int> customer: customers){
            if(currTime<customer[0]){
                currTime = customer[0];
            }
            sum += currTime - customer[0] + customer[1];
            currTime += customer[1];
        }
        double avg = (double)sum / (double)customers.size();
        return avg;
    }
};