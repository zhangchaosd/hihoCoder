#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <map>

//Debug x86
//use G++!!!!!!!!!!!!!!!!

using namespace std;

void S1014();
int hiho253();

int main()
{
	//printf("Hello hicoCoder!!");
	//S1014();
	int ans = hiho253();
	printf("%d", ans);
	return 0;
}


struct TrieTreeNode {
	char data;
	int cnt;
	map<char, TrieTreeNode*> childs;
	TrieTreeNode(char x) : data(x), cnt(0){}
};
void S1014()
{
	int n;
	cin >> n;
	string s;
	int sl;
	TrieTreeNode* root = new TrieTreeNode('0');
	TrieTreeNode* cur = root;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		sl = s.length();
		cur = root;
		for (int j = 0; j < sl; j++)
		{
			if (cur->childs[s[j]] == nullptr)
			{
				cur->childs[s[j]] = new TrieTreeNode(s[j]);
			}
			cur = cur->childs[s[j]];
			cur->cnt++;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		sl = s.length();
		cur = root;
		for (int j = 0; j < sl; j++)
		{
			cur = cur->childs[s[j]];
			if (cur == nullptr)
				break;
		}
		if (cur)
			printf("%d\n", cur->cnt);
		else
			printf("0\n");
	}
}


unsigned char vis[101][101];//0;1 left;2 right;3 all;
char mp[101][101];
int ans253;
int n, m;

void dfs(int x, int y,unsigned char b)
{
	char c = mp[x][y];

	vis[x][y] |= b;
	if (c == ' ')
		vis[x][y] = 3;

	if (x - 1 >= 0 && (c == ' ' || (c == '\\' && b == 2) || (c == '/' && b == 1)))
	{
		if (mp[x - 1][y] == ' ' && vis[x - 1][y] == 0)
			dfs(x - 1, y, 3);
		if (mp[x - 1][y] == '\\' && (vis[x - 1][y] == 0 || vis[x - 1][y] == 2))
			dfs(x - 1, y, 1);
		if (mp[x - 1][y] == '/' && (vis[x - 1][y] == 0 || vis[x - 1][y] == 1))
			dfs(x - 1, y, 2);
	}
	if (x + 1 < n && (c == ' ' || (c == '\\' && b == 1) || (c == '/' && b == 2)))
	{
		if (mp[x + 1][y] == ' ' && vis[x + 1][y] == 0)
			dfs(x + 1, y, 3);
		if (mp[x + 1][y] == '\\' && (vis[x + 1][y] == 0 || vis[x + 1][y] == 1))
			dfs(x + 1, y, 2);
		if (mp[x + 1][y] == '/' && (vis[x + 1][y] == 0 || vis[x + 1][y] == 2))
			dfs(x + 1, y, 1);
	}
	if (y - 1 >= 0 && (c == ' ' || b == 1))
	{
		if (mp[x][y - 1] == ' ' && vis[x][y - 1] == 0)
			dfs(x, y - 1, 3);
		else if (vis[x][y - 1] == 0 || vis[x][y - 1] == 1)
			dfs(x, y - 1, 2);
	}
	if (y + 1 < m && (c == ' ' || b == 2))
	{
		if (mp[x][y + 1] == ' ' && vis[x][y + 1] == 0)
			dfs(x, y + 1, 3);
		else if (vis[x][y + 1] == 0 || vis[x][y + 1] == 2)
			dfs(x, y + 1, 1);
	}
}

int hiho253()
{
	ans253 = 0;
	scanf("%d %d", &n, &m);
	char c=getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c = getchar();
			mp[i][j] = c;
		}
		getchar();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == 0 || vis[i][j] == 2)
			{
				ans253++;
				dfs(i, j, 1);
			}
			if (vis[i][j] == 0 || vis[i][j] == 1)
			{
				ans253++;
				dfs(i, j, 2);
			}
		}
	}
	return ans253;
}


