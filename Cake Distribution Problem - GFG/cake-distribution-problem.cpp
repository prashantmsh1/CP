//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool ifpossible(vector<int>& sweetness, int K,int mid)
    {
        int chunk=0;
        int sum=0;
        for(int x:sweetness){
            sum+=x;
            if(sum>=mid){
                chunk++;
                sum=0;
            }
        }
        return (chunk>=K+1);
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
      int low=INT_MAX;
    int high=0;
    int answer=0;
    for(int x: sweetness){
        high+=x;
        low=min(low,x);
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(ifpossible(sweetness,K,mid)){
            answer=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    return answer;
    // Write your code here.
   }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends