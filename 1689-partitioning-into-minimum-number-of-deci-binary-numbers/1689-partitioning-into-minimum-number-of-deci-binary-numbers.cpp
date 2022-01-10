class Solution {
public:
    int minPartitions(string n) {
        int max_digit = -1;
        for(int i=0;i<n.length();i++){
            if(n[i]-'0'>max_digit)
                max_digit=n[i]-'0';
        }
        return max_digit;
    }
};