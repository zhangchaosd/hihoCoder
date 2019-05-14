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
void S1015();
int hiho253();
void hiho254();

int main()
{
	//printf("Hello hicoCoder!!");
	//S1014();
	hiho254();
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


void S1015()
{
	int N;
	cin >> N;
	string s1, s2;
	for (int i = 0; i < N; i++)
	{
		cin >> s1 >> s2;
		int n1 = s1.size();
		int n2 = s2.size();
		vector<int>next(n1+1);
		{
			//getnext()
			next[0] = -1;
			int j = 0;
			int k = -1;
			while (j < n1)
			{
				if (k==-1||s1[k] == s1[j])
				{
					next[++j] = ++k;
				}
				else
					k = next[k];

			}

		}
		int i2 = 0;
		int j2 = 0;
		int ans = 0;
		while (i2 < n1 && j2 < n2)
		{
			if (i2==-1||s1[i2] == s2[j2])
			{
				i2++; j2++;
			}
			else
				i2 = next[i2];

			if (i2 == n1)
			{
				ans++;
				i2 = next[i2];
			}
		}
		printf("%d\n", ans);
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

void hiho254()
{
	int T;
	cin >> T;
	int N;
	while (T--)
	{
		long long s1 = 0, s2 = 0, s3 = 0, s4 = 0, t;
		cin >> N;
		while (N--)
		{
			cin >> t;
			if (t > s1)
			{
				if (t > s2)
				{
					if (t > s3)
					{
						if (t > s4)
						{
							s1 = s2;
							s2 = s3;
							s3 = s4;
							s4 = t;
						}
						else
						{
							s1 = s2;
							s2 = s3;
							s3 = t;
						}
					}
					else
					{
						s1 = s2;
						s2 = t;
					}
				}
				else
				{
					s1 = t;
				}
			}
		}
		long long ans = 0, tans = 0;
		long long ss[4] = { s1,s2,s3,s4 };
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				tans = ss[i] * ss[j] * (ss[i] & ss[j]);
				if (tans > ans)
					ans = tans;
			}
		}
		cout << ans << endl;
	}

}

