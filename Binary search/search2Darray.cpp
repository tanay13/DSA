// 0, 1, 2
// 3, 4, 5  -->  0, 1, 2, 3, 4, 5, 6, 7, 8
// 6, 7, 8
// Hence, matrix1[i][j] becomes matrix2[i * col_num + j], where i, j = 0, 1, 2, col_num = 3. Denote i * col_num + j by mid, then i = mid / col_num, and j = mid % col_num, hence matrix2[mid] = matrix1[mid / col_num][mid % col_num] = matrix1[i][j].



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    
    int i = matrix.size();
    int j = matrix[0].size();
    int total = i*j;
    int start = 0;
    int end = total-1;
    bool found = false;
   

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int mid_value = matrix[mid/j][mid%j];
        
        if(mid_value == target)
        {
            found = true;
            break;
         }
        
       else if(target>mid_value)
        {
            start = mid+1;
            
        }
        else
        {
            end = mid-1;
        }
       
    }
    
        
    return found;
        
    
        
        
    }
};