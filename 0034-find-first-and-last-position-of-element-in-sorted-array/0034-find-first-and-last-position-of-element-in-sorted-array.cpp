class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int first1 = first(nums,target);
        int second1 = second(nums,target);
        return {first1,second1};
    }

private:
    int first(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int first= -1;
        while (low <= high)
        { 

            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    first= mid;
                    break;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return first;
    }

    int second(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int second= -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (mid == nums.size()-1 || nums[mid + 1] != target)
                {
                    second= mid;
                    break;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return second;
    }
};