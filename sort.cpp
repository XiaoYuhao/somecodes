#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> &nums, int left, int right){
    int mid = left + (right - left) / 2;
    int pos = nums[mid];
    int p1 = left, p2 = right;
    while(p2>p1){
        while(p1<p2&&nums[p1]<pos) p1++;
        while(p1<p2&&nums[p2]>pos) p2--;
        swap(nums[p1], nums[p2]);
    }
    return p2;
}

void qsort(vector<int> &nums, int left, int right){
    if(left>=right) return;
    int pos = partition(nums, left, right);
    qsort(nums, left, pos);
    qsort(nums, pos+1, right);
}

void heapadjust(vector<int> &nums, int left, int right){
    int cur = left;
    if(cur*2>right) return;

    while(cur<=right){
        int c1 = cur*2;
        int c2 = cur*2+1;
        int sc = -1, maxn = 0x80000000;
        if(c1<=right&&maxn<nums[c1-1]){
            maxn = nums[c1-1];
            sc = c1;
        }
        if(c2<=right&&maxn<nums[c2-1]){
            maxn = nums[c2-1];
            sc = c2;
        }
        if(maxn>nums[cur-1]){
            swap(nums[cur-1], nums[sc-1]);
            cur = sc;
        }
        else break;
    }
}

void heapsort(vector<int> &nums){
    int n = nums.size();

    for(int i=n/2;i>0;i--){
        heapadjust(nums, i, n);
    }

    for(int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        heapadjust(nums, 1, i);
    }

    return;
}


vector<int> merge(vector<int> nums1, vector<int> nums2){
    int len1 = nums1.size();
    int len2 = nums2.size();
    int p1 = 0, p2 = 0;
    vector<int> res;
    while(p1<len1&&p2<len2){
        if(nums1[p1]<nums2[p2]){
            res.push_back(nums1[p1]);
            p1++;
        }
        else{
            res.push_back(nums2[p2]);
            p2++;
        }
    }
    while(p1<len1){
        res.push_back(nums1[p1]);
        p1++;
    }
    while(p2<len2){
        res.push_back(nums2[p2]);
        p2++;
    }
    return res;
}

void mergesort(vector<int> &nums, int left, int right){
    if(left>=right) return;
    vector<int> nums1, nums2;
    int mid = left + (right - left) / 2;
    for(int i=left;i<=mid;i++){
        nums1.push_back(nums[i]);
    }
    for(int i=mid+1;i<=right;i++){
        nums2.push_back(nums[i]);
    }
    /*
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl;
    */
    mergesort(nums1,0,nums1.size()-1);
    mergesort(nums2,0,nums2.size()-1);
    /*
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl;
    */
    nums = merge(nums1, nums2);
}

int main(){
    vector<int> nums = {3, 8, 1, 5, 9, 7, 6, 2, 4};
    
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    //qsort(nums, 0, nums.size()-1);
    //heapsort(nums);
    mergesort(nums, 0, nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}