
int activitySelection(int start[], int end[], int n){

    //creating pair of start and end 
    //of activities
    pair<int, int> p[n];
    for(int i=0;i<n;i++)
        p[i].second = start[i];
    for(int i=0;i<n;i++)
        p[i].first = end[i];
      
    //sorting activities  
    sort(p,p+n);
    
    //selecting activity which 
    //have start time greater than 
    //end time of previous activity--
    int i=0,j=1,ans=1;
    while(i<n&&j<n)
    {
        if(p[i].first<=p[j].second)
        {
            i=j;
            j++;
            ans++;
        }
        else
            j++;
    }
    return ans;
}