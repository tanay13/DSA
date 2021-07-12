class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    if(arr[0]<arr[n-1] || n==1)
	    {
	        return 0;
	    }
	    
	    int start = 0;
	    int end = n-1;
	    int rotated;
	    
	    while(start<=end)
	    {
	        int mid = start+(end-start)/2;
	        
	        if(arr[mid]==arr[n-1])
	        {
	            break;
	        }
	        
	        if(arr[mid]>arr[n-1])
	        {
	            rotated = mid+1;
	            start = mid+1;
	        }
	        
	        if(arr[mid]<arr[n-1])
	        {
	            end = mid-1;
	        }
	    }
	    
	    return rotated;
	}

}