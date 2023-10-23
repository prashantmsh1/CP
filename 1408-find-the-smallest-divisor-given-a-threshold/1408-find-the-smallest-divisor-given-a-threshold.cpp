class Solution {
public:
    bool thres(vector<int>& nums,int mid,int threshold){
        int count=0;
        for (auto& element : nums){
            if(element<mid)
            count++;
            else if(element%mid!=0){
                count+=element/mid+1;
            }
            else
             count+=element/mid;
        }
        if(count<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(thres(nums,mid,threshold)){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;
    }
};