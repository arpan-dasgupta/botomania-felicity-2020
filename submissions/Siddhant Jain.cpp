#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pll pair<ll, ll>
using namespace std;
 
typedef int ll;


ll gboard[12][12];

void assign_off(int x, int y, int offset_x, int offset_y, int myC, int board[12][12])
{
    for(int a=1; a<10; a++)
    {
        int newx=x+a*offset_x;
        int newy=y+a*offset_y;;
        if(newy>=10 ||  newy<0 || newx>=10 || newx<0)
            break;
        if(board[newx][newy]==myC)
        {
            for(int b=1; b<a; b++)
                board[x+b*offset_x][y+b*offset_y]=1;
            break;
        }
        else if(board[newx][newy]==0)
            break;
    }
}

void after_change(int x, int y, int myC, int board[12][12])
{
    board[x][y]=myC;
    assign_off(x, y, 1, 0, myC, board);
    assign_off(x, y, -1, 0, myC, board);
    assign_off(x, y, 0, 1, myC, board);
    assign_off(x, y, 0, -1, myC, board);
    assign_off(x, y, 1, 1, myC, board);
    assign_off(x, y, 1, -1, myC, board);
    assign_off(x, y, -1, 1, myC, board);
    assign_off(x, y, -1, -1, myC, board);
}


// bool is_valid(int x, int y, int myC, int board[12][12])
// {
//     int ret=0;

//     //HORIZONTAL RIGHT
//     int cnt=0;
//     for(int a=x+1; a<10; a++)
//     {
//         if(board[a][y]==myC)
//         {
//             ret+=cnt;
//             break;
//         }
//         else if(board[a][y]==3-myC)
//             cnt++;
//         else
//             break;
//     }

//     //HORIZONTAL LEFT
//     cnt=0;
//     for(int a=x-1; a>=0; a--)
//     {
//         if(board[a][y]==myC)
//         {
//             ret+=cnt;
//             break;
//         }
//         else if(board[a][y]==3-myC)
//             cnt++;
//         else
//             break;
//     }
    
//     //VERTICAL DOWN
//     cnt=0;
//     for(int a=y+1; a<10; a++)
//     {
//         if(board[x][a]==myC)
//         {
//             ret+=cnt;
//             break;
//         }
//         else if(board[x][a]==3-myC)
//             cnt++;
//         else
//             break;
//     }

//     //VERTICAL UP
//     for(int a=y-1; a>=0; a--)
//     {
//         if(board[x][a]==myC)
//         {
//             ret+=cnt;
//             break;
//         }
//         else if(board[x][a]==3-myC)
//             cnt++;
//         else
//             break;
//     }

    
//     cnt=0;
//     for(int a=1; a+x<10 && a+y<10; a++)
//     {
//         if(board[x+a][y+a]==myC)
//         {
//             ret+=cnt;
//             break;   
//         }
//         else if(board[x+a][y+a]==3-myC)
//             cnt++;
//         else
//             break;
//     }
//     cnt=0;
//     for(int a=1; x-a>=0 && a+y<10; a++)
//     {
//         if(board[x-a][y+a]==myC)
//         {
//             ret+=cnt;
//             break;   
//         }
//         else if(board[x-a][y+a]==3-myC)
//             cnt++;
//         else
//             break;
//     }
//     cnt=0;
//     for(int a=1; x-a>=0 && y-a>=0; a++)
//     {
//         if(board[x-a][y-a]==myC)
//         {
//             ret+=cnt;
//             break;   
//         }
//         else if(board[x-a][y-a]==3-myC)
//             cnt++;
//         else
//             break;
//     }
//     cnt=0;
//     for(int a=1; x+a>=0 && y-a>=0; a++)
//     {
//         if(board[x+a][y-a]==myC)
//         {
//             ret+=cnt;
//             break;   
//         }
//         else if(board[x+a][y-a]==3-myC)
//             cnt++;
//         else
//             break;
//     }
//     return ret;
// } 

int incre(int x, int y, int myC, int offset_x, int offset_y, int board[12][12])
{
    for(int a=1; a<10; a++)
    {
        int newx=x+a*offset_x;
        int newy=y+a*offset_y;
        if(newy>=10 || newy<0 || newx>=10 || newx<0)
            return 0;
        if(board[newx][newy]==myC)
            return a-1;
        else if(board[newx][newy]==0)
            return 0;
    }
    return 0;
}

bool is_valid(int x, int y, int myC, int board[12][12])
{
    int ret=0;
    ret+=incre(x, y, myC, 1, 0, board);
    ret+=incre(x, y, myC, 1, -1, board);
    ret+=incre(x, y, myC, 1, 1, board);
    ret+=incre(x, y, myC, -1, -1, board);
    ret+=incre(x, y, myC, -1, 0, board);
    ret+=incre(x, y, myC, -1, 1, board);
    ret+=incre(x, y, myC, 0, -1, board);
    ret+=incre(x, y, myC, 0, 1, board);
    return ret;

}

bool coord_valid(ll x, ll y){
    if(x>9||y>9||x<0||y<0)
        return 0;
    return 1;
}

ll positional_score(ll x, ll y, ll myC){
    ll ret=0, flag=0;
    if((x==0&&y==9)||(x==9&&y==9)||(x==0&&y==0)||(x==9&&y==0))
        ret=60;
    
    for(int i=x; i<10; i++){
        if(gboard[i][y]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;
    for(int i=x; i>=0; i--){
        if(gboard[i][y]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;
    for(int i=y; i>=0; i--){
        if(gboard[x][i]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;
    for(int i=y; i<10; i++){
        if(gboard[x][i]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;

    for(int i=x, j=y; coord_valid(i, j); i++, j++){
        if(gboard[i][j]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;
    for(int i=x, j=y; coord_valid(i, j); i--, j++){
        if(gboard[i][j]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;

    for(int i=x, j=y; coord_valid(i, j); i++, j--){
        if(gboard[i][j]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;

    for(int i=x, j=y; coord_valid(i, j); i--, j--){
        if(gboard[i][j]!=myC)
            flag=1;
    }
    if(flag==0)
        ret+=20;
    flag=0;

    ret*=2;
    ret/=3;

    return ret;
}

ll mob_score(ll myC){
    ll oppC=(myC%2)+1;
    ll ret=100;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            ll tmp=is_valid(i, j, oppC, gboard);
            ret -= tmp;
        }
    }
    return ret;
}

int main()
{
    ll board[12][12], myC;
    vector<pll> coords;
    ll score[12][12];
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>board[i][j];
            score[i][j]=0;
        }
    }

    cin>>myC;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(board[i][j]!=0)
                continue;
            ll captd_xy=is_valid(i, j, myC, board);
            if(captd_xy){
                score[i][j]=captd_xy;
                coords.pb({i,j});
            }
        }
    }

    if(coords.empty()){
        cout<<"-1\n-1";
        return 0;
    }

    for(auto c: coords){
        ll x=c.f, y=c.s;
        after_change(x, y, myC, board);
        ll posVal=positional_score(x, y, myC);
        after_change(x, y, myC, board);
        ll oppnMobScore=mob_score(myC);

        score[x][y]*=4*3;
        score[x][y]+=3*oppnMobScore+posVal*5;
    }

    ll outX, outY, scox=0;
    for(auto c: coords){
        ll x=c.f, y=c.s;
        if(score[x][y]>scox){
            scox=score[x][y];
            outX=x;
            outY=y;
        }
    }
    cout<<outX<<"\n"<<outY;
}