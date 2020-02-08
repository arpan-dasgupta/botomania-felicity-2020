#include <bits/stdc++.h>

using namespace std;

bool legal(long long arr[10][10],long long x,long long y,long long mv)
{
	if(arr[x][y])
		return false;
	long long i=x-1;
	long long j=y;
	while(i>=0 && arr[i][j]==(3-mv))
		i--;
	if(i!=-1 && arr[i][j]==mv && (x-i)>1)
		return true;
	i=x+1;
	while(i<=9 && arr[i][j]==(3-mv))
		i++;
	if(i!=10 && arr[i][j]==mv && (i-x)>1)
		return true;
	i=x;
	j=y-1;
	while(j>=0 && arr[i][j]==(3-mv))
		j--;
	if(j!=-1 && arr[i][j]==mv && (y-j)>1)
		return true;
	j=y+1;
	while(j<=9 && arr[i][j]==(3-mv))
		j++;
	if(j!=10 && arr[i][j]==mv && (j-y)>1)
		return true;
	i=x-1;
	j=y-1;
	while(i>=0 && j>=0 && arr[i][j]==(3-mv))
	{
		i--;
		j--;
	}
	if(i!=-1 && j!=-1 && arr[i][j]==mv && (y-j)>1 && (x-i)>1)
		return true;
	i=x+1;
	j=y+1;
	while(i<=9 && j<=9 && arr[i][j]==(3-mv))
	{
		i++;
		j++;
	}
	if(i!=10 && j!=10 && arr[i][j]==mv && (j-y)>1 && (i-x)>1)
		return true;
	i=x-1;
	j=y+1;
	while(i>=0 && j<=9 && arr[i][j]==(3-mv))
	{
		i--;
		j++;
	}
	if(i!=-1 && j!=10 && arr[i][j]==mv && (j-y)>1 && (x-i)>1)
		return true;
	i=x+1;
	j=y-1;
	while(i<=9 && j>=0 && arr[i][j]==(3-mv))
	{
		i++;
		j--;
	}
	if(i!=10 && j!=-1 && arr[i][j]==mv && (y-j)>1 && (i-x)>1)
		return true;
	return false;
}

long long gans = INT_MIN,r = -1,c = -1;

void calc_flip(long long arr[10][10],long long x,long long y,long long mv,long long d,long long ans,int ro,int co)
{
	if(d == 4)
	{
		if(ans > gans)
		{
			r = ro;
			c = co;
		}
		return;
	}
	if(!legal(arr,x,y,mv))
		return;
	long long temp[10][10];
	for(long long i=0;i<10;++i)
	{
		for(long long j=0;j<10;++j)
			temp[i][j] = arr[i][j];
	}
	int k;
	long long sum,tsum;
	bool flag;
	arr[x][y] ^= 3;
	if(x == 0)
	{
		sum = 2;
		if(y == 0 or y == 9)
			++sum;
	}
	else if(x == 9)
	{
		sum = 2;
		if(y == 0 or y == 9)
			++sum;
	}
	else
	{
		sum = 1;
		if(y == 0 or y == 9)
			++sum;
	}
	tsum = 0;
	flag = false;
	for(k = x+1;k<10;++k)
	{
		if(arr[k][y] == (mv^3))
		{
			++tsum;
			if(y == 0 or y == 9)
				++tsum;
		}
		else if(arr[k][y] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=x+1;i<k;++i)
			arr[i][y] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = x-1;k>=10;--k)
	{
		if(arr[k][y] == (mv^3))
		{
			arr[k][y] ^= 3;
			++tsum;
			if(y == 0 or y == 9)
				++tsum;
		}
		else if(arr[k][y] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=x-1;i>k;--i)
			arr[i][y] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = y+1;k<10;++k)
	{
		if(arr[x][k] == (mv^3))
		{
			arr[x][k] ^= 3;
			++tsum;
			if(x == 0 or x == 9)
				++tsum;
		}
		else if(arr[x][k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=y+1;i<k;++i)
			arr[x][i] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = y-1;k>=0;--k)
	{
		if(arr[x][k] == (mv^3))
		{
			arr[x][k] ^= 3;
			++tsum;
			if(x == 0 or x == 9)
				++tsum;
		}
		else if(arr[x][k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=y-1;i>k;--i)
			arr[x][i] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = 1;(x+k)<10 and (y+k)<10;++k)
	{
		if(arr[x+k][y+k] == (mv^3))
		{
			arr[x+k][y+k] ^= 3;
			++tsum;
		}
		else if(arr[x+k][y+k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=1;i<k;++i)
			arr[x+i][y+i] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = 1;(x-k)>=0 and (y-k)>=0;++k)
	{
		if(arr[x+k][y+k] == (mv^3))
		{
			arr[x+k][y+k] ^= 3;
			++tsum;
		}
		else if(arr[x+k][y+k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=1;i<k;++i)
			arr[x-i][y-i] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = 1;(x-k)>=0 and (y+k)<10;++k)
	{
		if(arr[x-k][y+k] == (mv^3))
		{
			arr[x-k][y+k] ^= 3;
			++tsum;
		}
		else if(arr[x-k][y+k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=1;i<k;++i)
			arr[x-i][y+i] ^= 3;
	}
	tsum = 0;
	flag = false;
	for(k = 1;(y-k)>=0 and (x+k)<10;++k)
	{
		if(arr[x+k][y-k] == (mv^3))
		{
			arr[x+k][y-k] ^= 3;
			++tsum;
		}
		else if(arr[x+k][y-k] == mv)
		{
			flag = true;
			break;
		}
		else
			break;
	}
	if(flag)
	{
		sum += tsum;
		for(int i=1;i<k;++i)
			arr[x+i][y-i] ^= 3;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if(d&1)
				calc_flip(arr,i,j,(mv^3),d+1,(ans-sum),ro,co);
			else
				calc_flip(arr,i,j,(mv^3),d+1,(ans+sum),ro,co);
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			arr[i][j] = temp[i][j];
	}
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	long long arr[10][10];
	long long mv;
	for(long long i=0;i<10;++i)
	{
		for(long long j=0;j<10;++j)
			cin >> arr[i][j];
	}
	cin >> mv;
	for(long long i=0;i<10;++i)
	{
		for(long long j=0;j<10;++j)
		{
			calc_flip(arr,i,j,mv,0,0,i,j);
		}
	}
	cout << r << endl << c << endl;
	return 0;
}