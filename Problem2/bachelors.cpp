#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


int main(){
int n_bachelors;
int n_spinsters;
vector<int> bachelors;
vector<int> spinsters;
int element;
int testcases = 0;

cin >> n_bachelors >> n_spinsters;
while(n_bachelors != 0 || n_spinsters != 0){
	testcases++;
	if(n_spinsters >= n_bachelors) { // If there's more spinters than bachelors, no bachelor will be alone
		for (int i = 0; i < n_bachelors; ++i)
		{
			cin >> element;
			
		}
		for (int i = 0; i < n_spinsters; ++i)
		{
			cin >> element;
					}
		cout << "Case " << testcases << ": " << "0" << endl;
		cin >> n_bachelors >> n_spinsters;
		continue;
	} 
	// else we need to find how many bachelors will be alone
	// and the one with the smallest age
	for (int i = 0; i < n_bachelors; ++i)
	{
		cin >> element;
		bachelors.push_back(element);
	}
	for (int i = 0; i < n_spinsters; ++i)
	{
		cin >> element;
		spinsters.push_back(element);
	}
	sort(bachelors.begin(), bachelors.end(), less<int>());
	
	cout << "Case " << testcases << ": " << n_bachelors - n_spinsters << " "<< bachelors.front() << endl;
	

	
	bachelors.clear();
	spinsters.clear();
	cin >> n_bachelors >> n_spinsters;
}

}