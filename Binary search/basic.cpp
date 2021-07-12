int searchInSorted(int arr[], int N, int K) 
{ 
    
       // Your code here
       int start = 0;
       int end = N-1;
       
       
       while(start<=end)
       {
           int mid = start + (end-start)/2; //to avoid the int overflow in case of very large value
           if(arr[mid] == K)
           return 1;
           
           else if(K>arr[mid])
           {
               start = mid+1;
           }
             
           else
             {
                 end = mid-1;
             }
       }
       
       return -1;
}