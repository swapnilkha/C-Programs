/* Given a vector of ints, some of which are duplicates, write a function that returns all the duplicate
elements in the vector in the form of vector<int>. Must be done on O(n) average time. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicates(vector<int> v)
{
	vector<int> result;
	unordered_map<int,int> m; //unordered map lookup and find is O(1) average time.
	unordered_map<int,int>:: iterator itr;

  	//traverse the vector 
	for(int i = 0; i < v.size(); i++)
	{
    		//if elem in vector is in the map, increment the key's value by 1, else set it to 0
		if(m.find(v[i]) != m.end()) {m[v[i]] += 1;}
		else {m[v[i]] = 0;}
	}

  	//traverse the unordered map using iterator, if # of occurrences > 0, push that elem into result vector
	for(itr = m.begin(); itr != m.end(); itr++)
	{
		if(itr->second > 0) result.push_back(itr->first);
	}

  	//finally return a vector containing all the duplicate values
	return result;
}

//test the above function
int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(1);
	
	for(int i = 0; i < findDuplicates(v).size(); i++) 
    		cout << findDuplicates(v)[i]<< endl;
    		//in this case should print 4, 3
}
