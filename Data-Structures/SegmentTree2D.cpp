#include <bits/stdc++.h>
using namespace std;

struct SegmentTree2D
{
    int n, m;
    vector<vector<int>> t;
    vector<vector<int>> a;

    SegmentTree2D(int n, int m)
    {
        this->n = n;
        this->m = m;
        t.assign(4 * n, vector<int>(4 * m));
    }

    SegmentTree2D(vector<vector<int>> &a)
    {
        this->a = a;
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
    {
        if (ly == ry)
        {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        }
        else
        {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy * 2, ly, my);
            build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
            t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
        }
    }

    void build_x(int vx, int lx, int rx)
    {
        if (lx != rx)
        {
            int mx = (lx + rx) / 2;
            build_x(vx * 2, lx, mx);
            build_x(vx * 2 + 1, mx + 1, rx);
        }
        build_y(vx, lx, rx, 1, 0, m - 1);
    }

    int sum_y(int vx, int vy, int tly, int try_, int ly, int ry)
    {
        if (ly > ry)
            return 0;
        if (ly == tly && try_ == ry)
            return t[vx][vy];
        int tmy = (tly + try_) / 2;
        return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)) + sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
    }

    int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
    {
        if (lx > rx)
            return 0;
        if (lx == tlx && trx == rx)
            return sum_y(vx, 1, 0, m - 1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry) + sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
    }
};

int main()
{
    
}
