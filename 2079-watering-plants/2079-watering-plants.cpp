class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, water = capacity;
        int n = plants.size();
        for(int i=-1;i<n-1;i++){
            if(water>=plants[i+1]){
                water-=plants[i+1];
                steps++;
            }
            else{
                steps+=2*(i+1) + 1;
                water = capacity - plants[i+1];
            }
        }
        return steps;
    }
};