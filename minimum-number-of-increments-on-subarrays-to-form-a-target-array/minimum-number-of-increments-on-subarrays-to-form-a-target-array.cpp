const int LIM = 1e5 + 5;

int segmentTree[4 * LIM], a[LIM];

void build(int index, int l, int r)
{
    if (l == r)
        segmentTree[index] = l;
    else
    {
        int mid = (l + r) / 2;

        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        
        if(a[segmentTree[index * 2]] <= a[segmentTree[index * 2 + 1]])
            segmentTree[index] = segmentTree[index * 2];
        else
            segmentTree[index] = segmentTree[index * 2 + 1];
    }
}

int query(int index, int curL, int curR, int queryL, int queryR)
{
    if (queryR < curL || queryL > curR)
        return -1;

    if (queryL <= curL && queryR >= curR)
        return segmentTree[index];

    int mid = (curL + curR) / 2;

    int index1 = query(2 * index, curL, mid, queryL, queryR);
    int index2 = query(2 * index + 1, mid + 1, curR, queryL, queryR);
    
    if(index1 == -1)
        return index2;
    else if(index2 == -1)
        return index1;
    else
    {
        if(a[index1] <= a[index2])
            return index1;
        else
            return index2;
    }
}

int getAnswer(int l, int r, int cur, int n)
{
    if(l > r)
        return 0;
    
    int index = query(1, 0, n-1, l, r);
    
    return abs(cur - a[index]) + getAnswer(l, index-1, a[index], n) + getAnswer(index + 1, r, a[index], n);
}

bool check(int a, int b, int c)
{
    if((b < a && b < c) || (b > a && b > c))
        return true;
    else
        return false;
}

class Solution {
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n = target.size();
        
        auto ip = unique(target.begin(), target.end());
        target.resize(distance(target.begin(), ip));
        
        n = target.size();
        
        int cur = 0;
        
        for(int i=0; i<n; ++i)
        {
            if(i == 0 || i == n-1)
                a[cur++] = target[i];
            else if(check(target[i-1], target[i], target[i+1]))
                a[cur++] = target[i];
        }
        
        n = cur;
        
        for(int i=0; i<n; ++i)
            cout << a[i] << " ";
        cout << endl;
        
        build(1, 0, n-1);
        
        return getAnswer(0, n-1, 0, n);
    }
};