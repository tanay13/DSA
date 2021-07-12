class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int start = 0;
    int end = n-1;
    int first = -1;
    int last = -1;

    
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        
        if(arr[mid]==x)
        {
            first = mid;
            end = mid-1;
        }
        
        if(arr[mid]>x)
        {
            end = mid-1;
        }
        if(arr[mid]<x)
        {
           start = mid+1;
        }
    }
    
    start = 0;
    end = n-1;
    
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        
        if(arr[mid]==x)
        {
            last = mid;
            start = mid+1;
        }
        
        if(arr[mid]>x)
        {
            end = mid-1;
        }
        if(arr[mid]<x)
        {
            start = mid+1;
        }
    }
    
    if(first==-1 && last==-1)
    return 0;
    else
    {
        return (last-first+1);
    }
    
    
    
   }
};