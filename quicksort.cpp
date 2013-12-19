/* QUICK SORT */

#include <iostream>
#include <vector>
using namespace std;

int quick(vector<int> &a, int n, int beg, int end)
{
	int left, right, loc = beg;
	cout<<"left is :" << left << ",right is: " << right << ", loc is : " << loc << endl;
	while(left != right){
		left = beg, right = end;
		cout << "we are in the first while loop" << endl;
		cout<<"left is :" << left << ",right is: " << right << ", loc is : " << loc << endl;
		while(a[loc]<a[right] && loc!=right)
			  right--;
		cout << " we are in nested while loop " << endl;
		cout<<"left is :" << left << ",right is: " << right << ", loc is : " << loc << endl;
		
		if(a[loc]>a[right]){
                  cout << " a[loc] > a [right]" << endl;
		  int temp = a[right];
		  a[right] = a[loc];
		  a[loc] = temp;
		  cout << "elements swapped" << endl << "right is : " << right << " loc is " << loc<<endl;
	}
	
	loc = right;
	cout << "shifted loc to right" << endl << "loc is " << loc << endl;
	
	while(a[loc] > a[left] && loc!=left)
	  left++;
	cout << "left is: "<<left<<endl;
	if(a[loc] < a[left]){
	  int temp = a[loc];
	  a[loc] = a[left];
	  a[left] = temp;
	}
	loc = left;
	cout<< "shifted loc to left"<<endl<<"loc is"<<loc<<endl;
	}
	return loc;
}
	  
main()
{
	vector<int> val(20), lower(20), upper(20);
	int n, top = 0, beg, end;
	cout <<"enter number of elements ";
	cin >> n;
	cout<<"enter values"<<endl;
	for(int i =1; i<=n; i++){
	  cout << i <<": ";
	  cin >> val[i];
	}
	if(n>1){
	top++;
	lower[1] = 1;
	upper[1] = n;
	}
	while(top!=0){
	beg = lower[top]; end = upper[top];
	top--;
	cout<<"top is: "<<top<<"beg is "<<beg<<"end is: "<<end<<endl;
	int loc = quick(val, n, beg, end);
//	cout << "loc = "<<loc<<endl;
	if(beg < loc-1){
	  top++; lower[top] = beg;
	  upper[top] = loc-1;
	}
	if(loc+1 < end){
	  top++; lower[top] = loc+1;
	  upper[top] = end;
	}
	}
	for(int j=1; j<=n; j++)
	cout<<" "<<val[j];
}
