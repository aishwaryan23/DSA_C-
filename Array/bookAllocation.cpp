//important problem(hard level)
#include<iostream>
#include<vector>
using namespace std;
bool Isvalid(vector<int> &arr,int n,int m,int allowedPages){
    int stu=1,pages=0;
    for(int i=0;i<n;i++){//O(n)
        if(arr[i]>allowedPages){
            return false;
        }
        if(pages+arr[i]<=allowedPages){
            pages+=arr[i];
        }else{
            stu++;
            pages=arr[i];
        }
    }
    return stu > m ?false : true;
}
int allocateBooks(vector<int> &arr,int n,int m){//O(logN * n)
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++)//O(n)
    {
        sum+=arr[i];
    }
    int st=0,end=sum,ans=-1;//range of values between  in and max
    while(st<=end){//O(logN)
        int mid=st+(end-st)/2;
        if(Isvalid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={2,1,3,4};
    int n=4,m=2;
    cout<<allocateBooks(arr,n,m);
    return 0;
}