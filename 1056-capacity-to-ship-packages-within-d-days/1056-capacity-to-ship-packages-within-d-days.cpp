class Solution {
public:
    bool thres(vector<int> &nums,int mid,int days){
        int count=1;
        int sum=0;
        for(auto& element:nums){
               sum+=element;
               if(element>mid)
               return false;
               if(sum>mid){
                   count++;
                   sum=element;
               }

        }
        if(count<=days)
        return true;
        else 
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=INT_MAX;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(thres(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};