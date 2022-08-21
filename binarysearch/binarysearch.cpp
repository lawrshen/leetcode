#include <vector>
using namespace std;

// meituan first round 2022/08/17
int mylower_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

// 33 https://leetcode.cn/problems/search-in-rotated-sorted-array/
int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < nums[r]) {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return -1;
}

// 81 https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/
bool searchii(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
            l++;
            r--;
        } else if (nums[mid] >= nums[l]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

// offer53 https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/
int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// 1095 https://leetcode.cn/problems/find-in-mountain-array/

class MountainArray {
public:
    int get(int index);
    int length();
};

int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) > mountainArr.get(mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    if (mountainArr.get(r) == target)
        return r;
    int t = r;
    l = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (mountainArr.get(l) == target)
        return l;
    l = t + 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) <= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (mountainArr.get(l) == target)
        return l;
    return -1;
}