class Solution {
public:
    int reversePairs(vector<int>& record) {
        vector<int> tmp(record.size());
        return merge_sort(0, record.size() - 1, record, tmp);
    }

    int merge_sort(int l, int r, vector<int>& record, vector<int>& tmp)
    {
        if(l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        int res = merge_sort(l, mid, record, tmp) + merge_sort(mid + 1, r, record, tmp);
        int i = l, j = mid + 1;
        for(int k = l; k <= r; k++)
        {
            tmp[k] = record[k];
        }
        for(int k = l; k <= r; k++)
        {
            if(i > mid)
                record[k] = tmp[j++];
            else if(j > r || tmp[i] <= tmp[j])
                record[k] = tmp[i++];
            else
            {
                record[k] = tmp[j++];
                res += mid - i + 1;
            }
        }
        return res;
    }
};