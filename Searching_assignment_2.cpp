// Q1)  Write a program to apply binary search in array sorted in decreasing order.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={8,6,5,3,1,0};
    int n=v.size(),l=0,r=n-1,mid,target=1;
    bool flag=false;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(target==v[mid]) 
        {
            flag=true;
            break;
        }
        else if(target>v[mid]) r=mid-1;
        else if(target<v[mid]) l=mid+1;
    }
    if(flag==true) cout<<"found at index = "<<mid;
    else           cout<<"not found";
}




// Q2)  You have a sorted array of infinite numbers, how would you search an element in the array?
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={1,4,6,7,9,13,15,18,20,22,24,27,29,31,33,35,36,38,40,43,47,49,52,57,60,63,69,70,71,73,75,78,79,81,84,86,89,90,91,93,95,98,99,100,101, 104, 106, 107, 109, 113, 115, 118, 120, 122, 124, 127, 129, 131, 133, 135, 136, 138, 140, 143, 147, 149, 152, 157, 160, 163, 169, 170, 171, 173, 175, 178, 179, 181, 184, 186, 189, 190, 191, 193, 195, 198, 199, 200,201, 204, 206, 207, 209, 213, 215, 218, 220, 222, 224, 227, 229, 231, 233, 235, 236, 238, 240, 243, 247, 249, 252, 257, 260, 263, 269, 270, 271, 273, 275, 278, 279, 281, 284, 286, 289, 290, 291, 293, 295, 298, 299, 300};
    int l=0,r=0,mid,n=1,target=115;
    bool flag=false;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(target==v[mid]) 
        {
            flag=true;
            break;
        } 
        else if(target>v[r]) 
        {
            l=r+1;
            r=r+2*n;
        }
        else if(target>v[mid]) l=mid+1;
        else if(target<v[mid]) r=mid-1;
        n*=2
    }
    if(flag==true) cout<<"found at index = "<<mid;
    else           cout<<"not found";
}




//You are given an m x n integer matrix matrix with the following two properties:
//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> v={{1,3,5,7,9},{13,16,20,22,23},{28,31,35,36,38},{45,46,47,50,51},{53,54,57,59,61},{62,64,67,69,71},{80,85,87,89,92}};
    int l,r,mid,nr=v.size(),nc=v[0].size(),i=0,j=nc-1,target=100,row,column;
    bool flag=false;
    //search row number
    l=0,r=nr-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(target==v[mid][j]) 
        {
            flag=true;
            row=mid;
            column=j;
            break;
        }
        else if (target>v[mid][j]) l=mid+1;
        else if (target<v[mid][j]) r=mid-1;
    }
    i=l;
    //search coloumn number
    if(flag==false && i<nr)
    {
        l=0,r=nc-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(target==v[i][mid])
            {
                flag=true;
                row=i;
                column=mid;
                break;
            }
            else if(target>v[i][mid]) l=mid+1;
            else if(target<v[i][mid]) r=mid-1;
        }
    }
    //result
    if(flag==true) cout<<"found at index = "<<row<<" "<<column;
    else           cout<<"not found";
}




// Q4) find a target in rotated repeated array
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v={8,10,2,3,5,7};
    int n=v.size(),l=0,r=n-1,mid,idx=-1,target=0;
    while(l<=r)
        {
            mid=l+(r-l)/2;
            if(target==v[mid]) 
            {
                idx=mid;
                break;
            }
            else if(v[mid]==v[l] && v[mid]==v[r])
            {
                l++;
                r--;
            }
            else if(v[mid]<=v[r])
            {
                if(target>=v[mid] && target<=v[r]) l=mid+1;
                else                               r=mid-1;
            }
            else
            {
                if(target>=v[l] && target<=v[mid]) r=mid-1;
                else                               l=mid+1;
            }
        }
        cout<<idx;
}