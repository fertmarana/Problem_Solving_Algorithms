#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


int main(){
int n;
int d;
int r;
int element;
int sum;
vector<int> mornings;
vector<int> evenings;

cin >> n >> d >> r;

while(n!= 0){
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> element;
		mornings.push_back(element);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> element;
		evenings.push_back(element);
	}
	sort(mornings.begin(), mornings.end(), less<int>());
	sort(evenings.begin(), evenings.end(), greater<int>());
	int total;
	for (int i = 0; i < n; ++i)
	{
		total = mornings[i]+evenings[i];

		if(total >= d){
			sum += r*(total-d);
		}
	}
	cout << sum << endl;
	mornings.clear();
	evenings.clear();
	cin >> n >> d >> r;
}


}