#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define pr pair <int, int>

void merge(int start, int mid, int end, int array[][3] )
{
	int n1=mid-start+1,n2=end-mid,j=0,k=0,l=start;
	int left[n1][3],right[n2][3];
	for (int i = 0; i < n1; ++i)
	{
		for (int p = 0; p < 3; ++p)
			left[i][p]=array[start+i][p];
	}
	for (int i = 0; i < n2; ++i)
	{
		for (int p = 0; p < 3; ++p)
			right[i][p]=array[mid+1+i][p];
	}
	while(j<n1 && k<n2)
	{
		if (left[j][2]>=right[k][2])
		{
			for (int p = 0; p < 3; ++p)
				array[l][p]=left[j][p];
			j++;
		}
		else
		{
			for (int p = 0; p < 3; ++p)
				array[l][p]=right[k][p];
			k++;
		}
		l++;
	}
	while(j<n1)
	{
		for (int p = 0; p < 3; ++p)
			array[l][p]=left[j][p];
		j++;
		l++;
	}
	while(k<n2)
	{
		for (int p = 0; p < 3; ++p)
			array[l][p]=right[k][p];
		l++;
		k++;
	}
}

void mergesort(int left, int right, int array[][3]) 
{ 
	if (left < right) 
	{ 
		int mid = (left+right)/2;  
		mergesort(left,mid,array); 
		mergesort(mid+1, right,array); 
		merge(left, mid, right,array); 
	} 
}

int main()
{
	freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
	int board[10][10], player ,index;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			cin >> board[i][j];
	}
	cin >> player;
	index = 0;
	int arr[100][3] = {0}, l;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if(board[i][j] == player)
			{

				int flag = 0, k, lastflag = 0;
				for (k = j+1; k < 10; ++k)
				{
					if(board[i][k] != 0 && board[i][k] != player)
						flag = 1;
					if(board[i][k] == 0)
						break;
					if(board[i][k] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = i;
					arr[index][1] = k;
					arr[index][2] += k-j;
					if(k == 9)
						arr[index][2] += k-j;
					index++;
				}
				flag = 0;
				for (k = j-1; k >= 0; --k)
				{
					if(board[i][k] != 0 && board[i][k] != player)
						flag = 1;
					if(board[i][k] == 0)
						break;
					if(board[i][k] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = i;
					arr[index][1] = k;
					arr[index][2] += j - k;
					if(k == 0)
						arr[index][2] += j - k;
					index++;
				}


				flag = 0;
				for (k = i-1; k >= 0; --k)
				{
					if(board[k][j] != 0 && board[k][j] != player)
						flag = 1;
					if(board[k][j] == 0)
						break;
					if(board[k][j] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = j;
					arr[index][2] += i - k;
					if(k == 0)
						arr[index][2] += i - k;
					index++;
				}
				flag = 0;
				for (k = i+1; k < 10; ++k)
				{
					if(board[k][j] != 0 && board[k][j] != player)
						flag = 1;
					if(board[k][j] == 0)
						break;
					if(board[k][j] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = j;
					arr[index][2] += k - i;
					if(k == 9)
						arr[index][2] += k - i;
					index++;
				}
				flag = 0;


				

				for (k = i+1, l = j+1; k < 10 && l < 10; ++k, ++l)
				{
					if(board[k][l] != 0 && board[k][l] != player)
						flag = 1;
					if(board[k][l] == 0)
						break;
					if(board[k][l] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = l;
					arr[index][2] += k - i;
					if(k == 9 || l == 9)
						arr[index][2] += k - i;
					index++;
				}
				flag = 0;
				for (k = i+1, l = j-1; k < 10 && l >= 0; ++k, --l)
				{
					if(board[k][l] != 0 && board[k][l] != player)
						flag = 1;
					if(board[k][l] == 0)
						break;
					if(board[k][l] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = l;
					if(k == 9 || l == 0)
						arr[index][2] += k - i;
					arr[index][2] += k - i;
					index++;
				}
				flag = 0;
				for (k = i-1, l = j+1; k >= 0 && l < 10; --k, ++l)
				{
					if(board[k][l] != 0 && board[k][l] != player)
						flag = 1;
					if(board[k][l] == 0)
						break;
					if(board[k][l] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = l;
					if(k == 0 || l == 9)
						arr[index][2] += l - j;
					arr[index][2] += l - j;
					index++;
				}
				flag = 0;
				for (k = i-1, l = j-1; k >= 0 && l >= 0; --k, --l)
				{
					if(board[k][l] != 0 && board[k][l] != player)
						flag = 1;
					if(board[k][l] == 0)
						break;
					if(board[k][l] == player)
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					arr[index][0] = k;
					arr[index][1] = l;
					arr[index][2] += i - k;
					if(k == 0 || l == 0)
						arr[index][2] += i - k;
					index++;
				}
			}
		}

	}
	if(index == 0)
	{
		cout << -1 << endl << -1 << endl;
		return 0;
	}
	mergesort(0, index-1, arr);
	cout << arr[0][0] << endl << arr[0][1] << endl;
	return 0;
}