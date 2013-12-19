/* MERGE SORT */

#include <iostream>
#include <vector>
using namespace std;

void mergepass (vector<int> &a, int low, int mid, int high)
{
	vector<int> b(20);
	int h = low, i = low, j = mid+1, k;
	while((h<=mid) && (j<=high)){
	  if(a[h] < a[j]){
	    b[i++] = a[h++];
	  }
	  else{
	    b[i++] = a[j++];
	  }
	}
	if(h>mid){
	  for(k = j; k<=high; k++){
	    b[i] = a[k];
	    i++;
	  }
	}
	else{
	  for(k=h; k<=mid; k++){
	   b[i] = a[k];
	   i++;
	  }
	}
	for( k=low; k<=high; k++)
	  a[k] = b[k];
}

void mergesort(vector<int> &a, int low, int high)
{
	if(low != high){
	int  mid= (low+high)/2;
	mergesort(a,low, mid);
	cout << "low = "<<low<<" " <<"mid = "<<mid<<"high= "<<high<<endl;
	mergesort(a, mid+1, high);
	cout << "low2 = "<<low<<" " <<"mid2 = "<<mid<<"high2= "<<high<<endl<<endl;
	mergepass(a, low, mid, high);
	cout << "low3 = "<<low<<" " <<"mid3 = "<<mid<<"high3= "<<high<<endl<<endl;
	}
}

main()
{
	vector<int> v(20);
	int n, low, high;
	cout<<"enter number of elements";
	cin>> n;
	cout<<"enter values"<<endl;
	for(int i=1; i<=n; i++){
	 cout<<i<<": ";
	 cin>>v[i];
	}
	low = 1; high = n;
	mergesort(v, low, high);
	for (int j=1; j<=n; j++)
	  cout<<v[j]<<" ";
}
