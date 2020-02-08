#include <bits/stdc++.h>
using namespace std;
#define BK 1
#define WH 2
#define pii pair<int, int>
#define cele const pair<pii, int> &
// #define dbg

int gameb[10][10];
int ourc;

bool iscorner(const pii &a){
	static set<pii> s;
	s.emplace(0,0);
	s.emplace(0,9);
	s.emplace(9,0);
	s.emplace(9,9);
	return s.count(a)==1;
}

bool isff(const pii &a){
	if(a.first >=3 && a.second >=3){
		if(a.first <7 && a.second <7)
			return true;
	}
		return false;
	}

// bool comp(const pair<pii, int> &a , const pair<pii, int> &b){
	auto  comp= [](pair<pii, int> a ,pair<pii, int> b){
		int pa=0, pb=0;
		if(iscorner(a.first)){
			pa=100;
		}
		else if(isff(a.first)){
			pa= 50;
		}

		if(iscorner(b.first)){
			pb=100;
		}
		else if(isff(b.first)){
			pb= 50;
		}

		pa += a.second;
		pb+= b.second;

		return pa > pb;
	};

	int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

		int ourc, oppc;
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++)
				cin>>gameb[i][j];
		}
		cin>>ourc;
		oppc= (ourc == 1)? 2 : 1;

		priority_queue<pair<pii,int> , vector<pair<pii,int>>,  decltype(comp)> pq(comp);
		#ifdef dbg
			cerr<<"@";
		#endif
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(gameb[i][j]== oppc){
					#ifdef dbg
						cerr<<i<<" "<<j<<endl;
					#endif


					int cnt=0, ii, jj;
					if(i!=0){
						cnt=0;
						for(ii= i; ii<9; ii++){
							if(gameb[ii][jj]== oppc)
								cnt++;
							else
								break;
						}
						if(gameb[ii][j] == ourc && gameb[i-1][j]==0)
							pq.push(make_pair(make_pair(i-1, j), cnt));
						else if (gameb[ii][j] == 0 && gameb[i-1][j]== ourc)
							pq.push(make_pair(make_pair(ii, j), cnt));
					}

					if(j!=0){
						cnt=0;
						for(jj= j; jj<9; jj++){
							if(gameb[i][jj]== oppc)
								cnt++;
							else
								break;
						}
						if(gameb[i][jj] == ourc && gameb[i][j-1]==0)
							pq.push(make_pair(make_pair(i, j-1), cnt));
						else if (gameb[i][jj] == 0 && gameb[i][j-1]== ourc)
							pq.push(make_pair(make_pair(i, jj), cnt));
					}

					if(j!=0 && i!=0){
						cnt=0;
						for(jj= j, ii=i; jj<9 && ii<9; jj++, ii++){
							if(gameb[ii][jj]== oppc)
								cnt++;
							else
								break;
						}
						if(gameb[ii][jj] == ourc && gameb[i-1][j-1]==0)
							pq.push(make_pair(make_pair(i-1, j-1), cnt));
						else if (gameb[ii][jj] == 0 && gameb[i-1][j-1]== ourc)
							pq.push(make_pair(make_pair(ii, jj), cnt));
					}

					if(j!=9 && i!=0){
						cnt=0;
						for(jj= j, ii=i; jj>0 && ii<9; jj--, ii++){
							if(gameb[ii][jj]== oppc)
								cnt++;
							else
								break;
						}
						if(gameb[ii][jj] == ourc && gameb[i-1][j+1]==0)
							pq.push(make_pair(make_pair(i-1, j+1), cnt));
						else if (gameb[ii][jj] == 0 && gameb[i-1][j+1]== ourc)
							pq.push(make_pair(make_pair(ii, jj), cnt));
					}


			}
		}
	}
	if(!pq.empty())
	{
		cout<<pq.top().first.first<<endl;
		cout<<pq.top().first.second<<endl;
	}
	else
	{
		cout<<-1<<endl<<-1<<endl;
	}

}