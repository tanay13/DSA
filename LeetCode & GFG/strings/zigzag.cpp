class Solution {
public:
    
 string convert(string s, int numRows) {
        
        int len = s.length();
        
        char m[numRows][len];
        
        if(numRows == 1)
            return s;
        
       string res = "";
      
       for(int i = 0; i<numRows;i++)
       {
           for(int j = 0;i+j<len;j+=2*numRows-2)
           {
               res+=s[i+j];
               if (i != 0 && i != numRows - 1 && j + 2*numRows-2 - i < len)
                    res += s[j + 2*numRows-2 - i];
           }
       }
     
      return res;
        
        
    }
};
