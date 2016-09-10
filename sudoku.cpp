#include <bits/stdc++.h>

using namespace std;
const int MAXN = 16;
int N; // N X N sudoku
int bsize; //block size (sqrt(N));
int grid[MAXN][MAXN];
int blksolved, ans;
void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<grid[i][j]<<"    ";
        }
        cout<<"\n";
    }
}
void input()
{
    cin>>N;
    bsize = sqrt(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cur; cin>>cur;
            grid[i][j] = cur; //enter -1 for blank box
        }
    }
    cout<<"done input\n";
}
bool findblank(int (&grid)[MAXN][MAXN], int &i, int &j)
{
    for (i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == -1)
                return true;
        }
    }
    return false;
}
bool checki(int (&grid)[MAXN][MAXN], int i, int cur)
{
    for (int a = 0; a < N; a++)
    {
        if (grid[i][a] == cur) return false;
    }
    return true;
}
bool checkj(int (&grid)[MAXN][MAXN], int j, int cur)
{
    for (int a = 0; a < N; a++)
    {
        if (grid[a][j] == cur) return false;
    }
    return true;
}
bool checkblk(int (&grid)[MAXN][MAXN], int i, int j, int cur)
{
    for (int k = i; k < i + bsize; k++)
    {
        for (int l = j; l < j + bsize; l++)
        {
            if (grid[k][l]==cur)
            {
                return false;
            }
        }
    }
    return true;
}
bool ok(int (&grid)[MAXN][MAXN], int i, int j, int cur)
{
    if (checkblk(grid,i-i%bsize, j-j%bsize, cur) && checki(grid,i,cur) && checkj(grid,j,cur) )
        return true;
    return false;
}
bool recur(int (&grid)[MAXN][MAXN])
{
    int i, j;
    bool alldone = true;
    for (i = 0; i < N && alldone; i++)
    {
        for (j = 0; j < N && alldone; j++)
        {
            if (grid[i][j] == -1)
                { alldone = false; break;}
        }
        if (!alldone) break;
    }
    if (alldone) return true;
    for (int cur = 0; cur < N; cur++)
    {
        if (ok(grid, i,j, cur))
        {
            grid[i][j] = cur;
            if (recur(grid))
                return true;
            grid[i][j] = -1;
        }
    }
    return false;
}
int main()
{
    input();
    if (recur(grid))
    {
        print();
    }
    else
        cout<<"no solution\n";
}
