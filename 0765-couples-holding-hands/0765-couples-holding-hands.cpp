class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,int> m;
        for(int i =0 ;i < row.size(); ++i)
        m[row[i]] = i;
        int count  =0;
        for(int i =0;i < row.size(); i+=2)
        {
            int first = row[i];
            int second = first ^ 1;
            if(row[i+1] != second)
            {
                count++;
                int temp = row[i+1];
                int ind = m[second];
                swap(row[i+1], row[ind]);
                m[temp] = ind;
                m[second] = i+1;
            }
        }
        return count;
    }
};