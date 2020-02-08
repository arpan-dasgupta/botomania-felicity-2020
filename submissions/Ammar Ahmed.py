def insideboard(i,j):
    if(i<10 and i>0 and j<10 and j>0):
        return 1
    else:
        return 0
def checkvalid(x,y,i,j,pno):
    flag=0
    while(insideboard(x,y)):
        x+=i
        y+=j
        if(grid[x][y]==3-pno):
            flag=1
        elif grid[x][y]==0 and flag==1:
            return (x,y)
        elif grid[x][y]==0 and flag==0:
            return 0
        elif(grid[x][y]==pno):
            return 0

def get_valid(grid,pno):
    valid=[]
    for i in range(10):
        for j in range(10):
            if(grid[i][j]==pno):
                val=checkvalid(i,j,1,0,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,-1,0,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,0,1,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,0,-1,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,1,1,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,1,-1,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,-1,1,pno)
                if(val!=0):
                    valid.append(val)
                val=checkvalid(i,j,-1,-1,pno)
                if(val!=0):
                    valid.append(val)
    return valid

def getturn(pno,layer):
        if (pno-layer)%2==0:
            return 2
        else:
            return 1

def isitvalid(grid,x,y,i,j,pno):
    flag=0
    ogx=x
    ogy=y
    while(insideboard(x,y)):
        x+=i
        y+=j
        if(grid[x][y]==3-pno):
            flag=1
        elif grid[x][y]==0:
            return -1

        elif(grid[x][y]==pno and flag==1):
            break
    
    while ogx!=x or ogy!=y:
        ogx+=i
        ogy+=j
        grid[ogx][ogy]=pno
    return grid



def execute(grid,pos,pno):

    grid1=isitvalid(grid,pos[0],pos[1],1,0,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],-1,0,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],0,1,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],0,-1,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],1,1,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],1,-1,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],-1,1,pno)
    if grid1!=-1:
        grid=grid1
    grid1=isitvalid(grid,pos[0],pos[1],-1,-1,pno)
    if grid1!=-1:
        grid=grid1
    return grid

def findcost(grid, pno):
    cost=0
    for i in range(10):
        for j in range(10):
            if(grid[i][j]==pno):
                cost+=1
            elif (grid[i][j]==3-pno):
                cost-=1
            if (i==0 or i==9) and (j==0 or j==9):
                if(grid[i][j]==pno):
                    cost-=3
                elif grid[i][j]==3-pno:
                    cost+=3
    return cost

def gotochild(i,layer,pno,grid):
    if(layer<5):
        turn=getturn(pno,layer)
        nb=execute(grid,i,turn)

        valid=get_valid(nb,turn)
        cost=findcost(nb,turn)
        val=0
        if(turn==pno):
            val=100000000
            for j in valid:
                getcost=gotochild(j,layer,pno,grid)
                if getcost<val:
                    val=getcost
        else:
            val=-100000000
            for j in valid:
                getcost=gotochild(j,layer,pno,grid)
                if getcost>val:
                    val=getcost
        return val
    else:
        return findcost(nb,pno,layer)
def make_move(grid,pno):
    valid=get_valid(grid,pno)
    min=10000000000
    minval=()
    # print(valid)
    for i in valid:
        val=gotochild(i,0,pno,grid)
        if(val<min):
            min=val
            minval=i
    return minval
    


# grid=[]
# for i in range(10):
#     grid.append([])
#     for j in range(10):
#         grid[i].append(0)
# grid[4][4]=1
# grid[4][5]=2
# grid[5][4]=2
# grid[5][5]=1
# print(make_move(grid,2))