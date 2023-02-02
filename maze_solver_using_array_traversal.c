#include <stdio.h>

int hasPath(int size,int maze[size][size],int row, int col, int dest, int visited[size][size]){
    if(row<0||col<0||row>=size || col>=size || maze[row][col]==0) return 0;
    static int found=0;
    if(maze[row][col]==dest){
        found=1;
        return found;
    }
    
    visited[row][col]=1;
    if(maze[row][col+1]!=0 && visited[row][col+1]!=1) hasPath(size,maze,row,col+1,dest,visited);
    if(maze[row+1][col]!=0 && visited[row+1][col]!=1) hasPath(size,maze,row+1,col,dest,visited);
    if(maze[row][col-1]!=0 && visited[row][col-1]!=1) hasPath(size,maze,row,col-1,dest,visited);
    if(maze[row-1][col]!=0 && visited[row-1][col]!=1) hasPath(size,maze,row-1,col,dest,visited);
    visited[row][col]=0;
    return found;
}

int countPath(int size,int maze[size][size],int row, int col, int dest, int visited[size][size]){
    static int count=0;
    if(row<0||col<0||row>=size || col>=size || maze[row][col]==0) return 0;
    if(maze[row][col]==dest){
        count+=1;
        return 0;
    }
    
    visited[row][col]=1;
    if(maze[row][col+1]!=0 && visited[row][col+1]!=1) countPath(size,maze,row,col+1,dest,visited);
    if(maze[row+1][col]!=0 && visited[row+1][col]!=1) countPath(size,maze,row+1,col,dest,visited);
    if(maze[row][col-1]!=0 && visited[row][col-1]!=1) countPath(size,maze,row,col-1,dest,visited);
    if(maze[row-1][col]!=0 && visited[row-1][col]!=1) countPath(size,maze,row-1,col,dest,visited);
    visited[row][col]=0;
    return count;
}

int shortestPath(int size,int maze[size][size],int row, int col, int dest, int visited[size][size]){
    static int path_len=0, shortest=100;
   
    if(row<0||col<0||row>=size || col>=size || maze[row][col]==0) return 0;
    if(maze[row][col]==dest){
        if(path_len<shortest)
            shortest=path_len;
        return 0;
    }
    
    visited[row][col]=1;
    path_len+=1;
    if(maze[row][col+1]!=0 && visited[row][col+1]!=1) shortestPath(size,maze,row,col+1,dest,visited);
    if(maze[row+1][col]!=0 && visited[row+1][col]!=1) shortestPath(size,maze,row+1,col,dest,visited);
    if(maze[row][col-1]!=0 && visited[row][col-1]!=1) shortestPath(size,maze,row,col-1,dest,visited);
    if(maze[row-1][col]!=0 && visited[row-1][col]!=1) shortestPath(size,maze,row-1,col,dest,visited);
    visited[row][col]=0;
    path_len-=1;
    return shortest;
}


int main()
{
    int maze[10][10]={  {1,1,1,1,1,1,1,1,1,1},
                        {0,0,1,0,0,0,0,1,0,1},
                        {0,0,1,0,0,0,0,1,0,1},
                        {0,0,1,1,1,1,1,1,0,1},
                        {0,0,0,0,1,0,0,1,0,1},
                        {0,0,0,0,1,1,0,1,0,1},
                        {0,0,0,0,1,0,0,0,0,1},
                        {0,0,0,1,1,1,1,9,0,1},
                        {1,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0}
    };
    
    int size=10;
    int visited[10][10]={0};
    int start_row,start_col;
    printf("Enter start locations (start_row start_column): ");
    scanf("%d %d", &start_row, &start_col);
    
    
    int found=hasPath(size,maze,start_row,start_col,9, visited);
    if(found!=0) printf("Found path\n");
    else printf("Path not found");
    
    if(found){
        int paths= countPath(size,maze,start_row,start_col,9, visited);
        printf("Found %d paths to destination\n", paths);
        
        int shortest= shortestPath(size,maze,start_row,start_col,9, visited);
        printf("The shortest path is %d steps from start\n", shortest);
    }
    return 0;
}
