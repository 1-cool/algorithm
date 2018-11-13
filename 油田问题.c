#include<stdio.h>
char grid[101][101];//网格
int n,m;//行、列
//一个网格的8个方向
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

//从（x,y）进行深度优先遍历
void DFS(int x,int y)
{
    int xx,yy;
    grid[x][y]='*';//将grid中访问过的方块设置成‘*’，防止重复访问~
    for(int i=0;i<8;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx<0||xx>=n||yy<0||yy>=m)
            continue;//越界终止本次循环
        if(grid[xx][yy]=='@')
            DFS(xx,yy);//如果方格还是‘@’，则继续搜索
    }
}

int main()
{
    int i,j;//循环变量
    int count;//油田数量计数
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        count=0;
        for(i=0;i<n;i++)
            scanf("%s",grid[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(grid[i][j]=='@')
                {
                    DFS(i,j);count++;
                }//在（i,j）遍历，并且遍历了一个“油田”，计数器加1
        printf("%d\n",count);
    }
    return 0;
}
