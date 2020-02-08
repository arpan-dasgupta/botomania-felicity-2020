#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define all(X) X.begin(),X.end()
#define fin cin
#define fout cout

// for pair comparison function(ascending order) use return (i1.ff < i2.ff);

/* string operations :
   str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
   str.substr (x) : returns a substring str[x],... end of string
   str.find(qtr) : returns the first occurenece of qtr in str */

const int M = (1<<20)+5;
const int md = 1e9+7;

int n = 10;
int mn,oth;
int col;
int mat[15][15];

// ifstream fin ("input.in");
// ofstream fout ("output.out");

int opp(int u)
{
	if(u == 1)
		return 2;
	else
		return 1;
}

void board_inp()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			fin >> mat[i][j];
		}
	}
}

void get_cnt()
{
	mn = oth = 0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(mat[i][j] == col)
				mn++;
			else if(mat[i][j] == opp(col))
				oth++;
		}
	}
}

pi mnply()
{
	int ps = 100;
	int vx = -1,vy = -1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int cnt = 0;
			int k;
			if(mat[i][j] != 0)
				continue;
			for(k=j+1;k<n;++k)
			{
				if(mat[i][k] != opp(col))
					break;
				else
					cnt++;
			}
			if(mat[i][k] == 0)
				cnt -= (k-1-j);
			
			for(k=j-1;k>=0;k--)
			{
				if(mat[i][k] != opp(col))
					break;
				else
					cnt++;
			}
			if(k < 0 || mat[i][k] == 0)
				cnt -= (j-1-k);
			
			for(k=i+1;k<n;++k)
			{
				if(mat[k][j] != opp(col))
					break;
				else
					cnt++;
			}
			if(mat[k][j] == 0)
				cnt -= (k-1-i);
			
			for(k=i-1;k>=0;k--)
			{
				if(mat[k][j] != opp(col))
					break;
				else
					cnt++;
			}
			if(k < 0 || mat[k][j] == 0)
				cnt -= (i-1-k);

			for(k=1;i-k >= 0 && j-k >= 0;++k)
			{
				if(mat[i-k][j-k] != opp(col))
					break;
			}
			if(i-k >= 0 && j-k >= 0 && mat[i-k][j-k] == col)
				cnt += k-1;

			for(k=1;i-k >= 0 && j+k < n;++k)
			{
				if(mat[i-k][j+k] != opp(col))
					break;
			}
			if(i-k >= 0 && mat[i-k][j+k] == col)
				cnt += k-1;
			
			for(k=1;i+k < n && j-k >= 0;++k)
			{
				if(mat[i+k][j-k] != opp(col))
					break;
			}
			if(j-k >= 0 && mat[i+k][j-k] == col)
				cnt += k-1;
			
			for(k=1;i+k < n && j+k < n;++k)
			{
				if(mat[i-k][j-k] != opp(col))
					break;
			}
			if(mat[i+k][j+k] == col)
				cnt += k-1;
			
			if(cnt != 0 && ps > cnt)
			{
				ps = cnt;
				vx = i;
				vy = j;
			}
		}
	}

	return {vx,vy};
}

pi mxply()
{
	int ps = 0;
	int vx = -1,vy = -1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int cnt = 0;
			int k;
			if(mat[i][j] != 0)
				continue;
			for(k=j+1;k<n;++k)
			{
				if(mat[i][k] != opp(col))
					break;
				else
					cnt++;
			}
			if(mat[i][k] == 0)
				cnt -= (k-1-j);
			
			for(k=j-1;k>=0;k--)
			{
				if(mat[i][k] != opp(col))
					break;
				else
					cnt++;
			}
			if(k < 0 || mat[i][k] == 0)
				cnt -= (j-1-k);
			
			for(k=i+1;k<n;++k)
			{
				if(mat[k][j] != opp(col))
					break;
				else
					cnt++;
			}
			if(mat[k][j] == 0)
				cnt -= (k-1-i);
			
			for(k=i-1;k>=0;k--)
			{
				if(mat[k][j] != opp(col))
					break;
				else
					cnt++;
			}
			if(k < 0 || mat[k][j] == 0)
				cnt -= (i-1-k);

			for(k=1;i-k >= 0 && j-k >= 0;++k)
			{
				if(mat[i-k][j-k] != opp(col))
					break;
			}
			if(i-k >= 0 && j-k >= 0 && mat[i-k][j-k] == col)
				cnt += k-1;

			for(k=1;i-k >= 0 && j+k < n;++k)
			{
				if(mat[i-k][j+k] != opp(col))
					break;
			}
			if(i-k >= 0 && mat[i-k][j+k] == col)
				cnt += k-1;
			
			for(k=1;i+k < n && j-k >= 0;++k)
			{
				if(mat[i+k][j-k] != opp(col))
					break;
			}
			if(j-k >= 0 && mat[i+k][j-k] == col)
				cnt += k-1;
			
			for(k=1;i+k < n && j+k < n;++k)
			{
				if(mat[i-k][j-k] != opp(col))
					break;
			}
			if(mat[i+k][j+k] == col)
				cnt += k-1;
			
			if(cnt != 0 && ps < cnt)
			{
				ps = cnt;
				vx = i;
				vy = j;
			}
		}
	}

	return {vx,vy};
}

int main()
{
	int it,v;

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	board_inp();
	fin >> col;
	get_cnt();
	
	if(mn+oth <=70)
	{
		pi ed = mnply();
		fout << ed.ff << endl;
		fout << ed.ss << endl;
	}
	else
	{
		pi ed = mxply();
		fout << ed.ff << endl;
		fout << ed.ss << endl;
	}
		

	// fin.close();
	// fout.close();
	return 0;
}



    

	