/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        // for peak
        int L = 0, R = len - 1;
        while (L < R)
        {
            int mid = L + (R - L) / 2;
            int midVal = mountainArr.get(mid);
            int midNext = mountainArr.get(mid + 1);
            if (midVal < midNext)
            {
                L = mid + 1;
            }
            else
            {
                R = mid;
            }
        }
        int peakIdx = L;

        // for left of peak
        L = 0, R = peakIdx;
        while (L <= R)
        {
            int mid = L + (R - L) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target)
            {
                return mid;
            }
            else if (midVal > target)
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }

        // for right of peak
        L = peakIdx + 1, R = len - 1;
        while (L <= R)
        {
            int mid = L + (R - L) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target)
            {
                return mid;
            }
            else if (midVal > target)
            {
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        return -1;
    }
};