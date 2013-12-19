/* BUBBLE SORT */

#include <iostream>
#include <vector>
using namespace std;

main()
{
	vector<int> val(20);
	int n;
	cout << "enter no. of elements";
	cin >> n;
	cout << "enter values of elements";
	for (int i=1; i<=n; i++){
	  cout << i <<": ";
	  cin >> val[i];
	}
	
	for(int j=1; j<n; j++){ //number of passes 1 to n-1
	int ptr =1;
	while (ptr<=n-j){ //number of comparisons
	  if(val[ptr] > val[ptr+1]){
	    int temp = val[ptr];
	    val[ptr] = val[ptr+1];
	    val[ptr+1] = temp;
	  }
	ptr++;
	}
	}
	
	for(int k=1; k<=n; k++)
	  cout <<val[k]<<", ";
}
