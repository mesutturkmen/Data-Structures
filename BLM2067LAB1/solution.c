#include<stdio.h>
#define ROW 50
#define COLUMN 50

void DFS(int grid[ROW][COLUMN], int visited[ROW][COLUMN], int size[], int row, int col, int r, int c, int blobNum){
    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[r][c] = 1;
    
    
    for (size_t i = 0; i < 8; ++i)
    {
        if (((r + rowNum[i]) >= 0) && ((r + rowNum[i]) < row) && ((c + colNum[i]) >= 0) && ((c + colNum[i]) < col) && grid[r + rowNum[i]][c + colNum[i]] && !visited[r + rowNum[i]][c + colNum[i]])
            {
                size[blobNum]++;
                DFS(grid, visited, size, row, col, r + rowNum[i], c + colNum[i], blobNum);
            }   
    }
    
}

int main(){
    int row, col, blobRow, blobCol, count = 0;
    int grid[ROW][COLUMN] = {0};
    int visited[ROW][COLUMN] = {0};
    int size[] = {0};
    scanf("%d %d", &row, &col);
    

    scanf("%d %d", &blobRow, &blobCol);
    while (blobRow != -1)
    {
        grid[blobRow][blobCol] = 1;
        scanf("%d", &blobRow);
        if(blobRow == -1){
            break;
        }
        scanf("%d", &blobCol);
    }
    
    for (size_t r = 0; r < row; r++)
    {
        for (size_t c = 0; c < col; c++)
        {
            if(grid[r][c] && !visited[r][c]){
                size[count] = 1;
                DFS(grid, visited, size, row, col, r, c, count);
                count++;
            }   
        }
        
    }
    //putting sizes in ascending order
     int temp;
        for (size_t j = 0; j  < count - 1; j++)
        {
            for (size_t i = 0; i < count-1; i++)
        {
            if (size[i] > size[i+1])
            {
                temp = size[i];
                size[i] = size[i+1];
                size[i+1] = temp;
            }  
        }
        }
        
        
    
    printf("%d ", count);
     for (size_t i = 0; i < count; i++)
    {
        if(i == count - 1)
            printf("%d", size[i]);
        else
            printf("%d ", size[i]);
    }
    puts("");
}
