#include <queue>
#include <map>
#include <iostream>

using namespace std;


int main(){
	int test_cases;
	queue<int> fila;
	int n_men,n_women;
	int n_pars;
	map<int, int> pars;
	map<int, int> reverse_pars;
	int p_men[250][250], p_women[250][250]; // men and women preferences
	cin >> test_cases;
	for(int j=0; j<test_cases; j++){
		// INITIALIZING
		cin >> n_pars;
		n_men = n_pars;
		n_women = n_pars;
		for(int i=0;i<n_men;i++){
        	fila.push(i+1);
    	}
    	int element;
    	// List of preferences of men
    	for (int i=0; i<n_women; i++){
    		for (int k=0; k<= n_men; k++){
    			cin >> element;
    			if(k!=0) p_women[i][k-1] = element;
    		}
    	}
    	
    	// List of preferences of women
    	for (int i=0; i<n_men; i++){
    		for (int k=0; k<= n_women; k++){
    			cin >> element;
    			if(k!=0) p_men[i][k-1] = element;
    		}
    	}
    	
    
    	// APPLICATION
    	while(!fila.empty()){
    		int current_man = fila.front();
    		fila.pop();
    		//cout << "current_man: " << current_man << endl;
    		for(int index=0; index<= n_women; index++){
    			int woman = p_men[current_man-1][index];
    			//cout << "woman: " << woman << endl;
    			if(pars.find(woman) == pars.end()){ // woman is not married
    				pars.insert(pair<int, int>(woman, current_man));
    				//cout << "They married! " << woman << " <3 "<< pars[woman] << endl;
    				break;
    			} else{ // woman is married
    				//cout << "She is married :| " << endl;
    				auto it = pars.find(woman);  
    				int current_husband = it->second;
    				//cout << "current_husband: " << current_husband << endl;
    				// find out if she prefers current_men over the guy she is married to
    				int index_currentman = -1, index_currenthusband = -1;
    				for(int k=0; k< n_men; k++){
    					if(p_women[woman-1][k]== current_man){
    						index_currentman = k;
    					}
    					if(p_women[woman-1][k]== current_husband){
    						index_currenthusband = k;
    					}
    					if(index_currenthusband != -1 && index_currentman != -1){
    						break;
    					}
    				}
    				if(index_currentman < index_currenthusband){
    					pars[woman] = current_man;
    					fila.push(current_husband);
    					//cout << "She left the other one and They married! " << endl;
    					break;
    				}
    				//cout << "She is not interested "  << endl;


    			}
    		}

    	}
    	// PRINTING RESULTS
    	for(std::map<int,int>::iterator it = pars.begin(); it != pars.end(); it++) {
    		reverse_pars.insert(pair<int, int>(it->second, it->first));	
    	}
		for(std::map<int,int>::iterator it = reverse_pars.begin(); it != reverse_pars.end(); it++) {
    		cout << it->first << " " << it->second << "\n";
    	}
    	reverse_pars.clear();
    	pars.clear();


	}
	
}