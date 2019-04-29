#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

//Debug x86
//use G++!!!!!!!!!!!!!!!!

using namespace std;

void S1014();

int main()
{
	//printf("Hello hicoCoder!!");
	S1014();


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