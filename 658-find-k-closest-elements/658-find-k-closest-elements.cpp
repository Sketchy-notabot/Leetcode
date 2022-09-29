class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-k, mid;
        while(l<r){
            mid = (r+l)/2;
            if(x-arr[mid]>arr[mid+k]-x)
                l=mid+1;
            else
                r=mid;
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};