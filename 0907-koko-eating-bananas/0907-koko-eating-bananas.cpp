class Solution {
public:
     bool eatll(vector<int> &piles, int h, int mid){
        
        long long count=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<mid){
                count++;
            }
            else if(piles[i]%mid!=0){
                count+=(piles[i]/mid)+1;
            }
            else
            count+=piles[i]/mid;
        }
        if(count<=h)
        return true;
        else
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(),piles.end());
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low + (high-low)/2;
            if(eatll(piles,h,mid)){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }

   
};