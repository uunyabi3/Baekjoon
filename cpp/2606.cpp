#include <iostream>
#include <vector>
using namespace std;

bool visited[101];
vector<int> v[101];
int cnt = 0;  

void dfs(int x)
{
    cnt++;
    visited[x] = true;
    for(int i : v[x])
        if(!visited[i])
            dfs(i);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[1] = 1;
    dfs(1);
    cout << cnt - 1;
}