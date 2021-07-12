vector<int> find(int arr[], int n , int x )
{
    // code here
    int start = 0;
    int end = n-1;
    int first = -1;
    int last = -1;
    vector<int> v;
    
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
    
    v.push_back(first);
    v.push_back(last);
    return v;
}