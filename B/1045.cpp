#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
	if (start >= end) return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	for (;start1 <= end1 && start2 <= end2;)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	for (;start1 <= end1;)
		reg[k++] = arr[start1++];
	for (;start2 <= end2;)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}
template<typename T>
void merge_sort(T arr[], const int len) {
	T reg[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
}


bool judge(int *p,int n,int i)
{
    for(int j = i;j >= 0;j--)
        if(p[j] > p[i]) return false;
    for(int j = i;j < n;j++)
        if(p[j] < p[i]) return false;
    return true;
}

int main()
{
    int n,countn = 0;
    cin>>n;
    int (*p) = new int[n];int (*cp) = new int[n];
    for(int i = 0;i < n;i++) cin>>p[i];
    for(int i = 0;i < n;i++)
    {
        if(judge(p,n,i))
        {
            cp[countn] = p[i];
            countn++;
        }
    }
    cout<<countn<<endl;
    merge_sort(cp,countn);
    for(int i = 0;i < countn;i++)
    {
        if(!i) cout<<cp[i];
        else cout<<" "<<cp[i];
    }
    cout<<endl;
    delete [] p;delete [] cp;
}
