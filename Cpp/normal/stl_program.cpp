#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main(){
    vector<int> myVector;
    list<int> myList;
    deque<int> myQueue;
    map<string,int> myMap;
    set<int> mySet;
    
// 1. insert element -----------
    //Vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    //List
    myList.push_back(3);
    myList.push_front(2);
    myList.emplace_front(1); 
    myList.emplace_back(4);
    //deque
    myQueue.push_back(3);
    myQueue.push_front(2);
    myQueue.emplace_front(1); 
    myQueue.emplace_back(4); 
    //map
    myMap.insert(pair<string,int>("one",1));
    myMap["two"] =  2;
    auto itr = myMap.find("two");
    myMap.insert(itr,pair<string,int>("three",3)); 
    //set
    mySet.insert(1);
    mySet.insert(2);

    // 2 print element
    cout << "myVector" << endl;
    for(auto x: myVector)
        cout << x << ",";
    cout << endl;

    cout << "myList" << endl;
    for(auto x: myList)
        cout << x << ",";
    cout << endl;

    cout << "myQueue" << endl;
    for(auto x: myQueue)
        cout << x << ",";
    cout << endl;

    cout << "myMap" << endl;
    for(auto x: myMap)
        cout << x.first << ":" << x.second << ",";
    cout << endl;

    cout << "mySet" << endl;
    for(auto x: mySet)
        cout << x << ",";
    cout << endl;
}
