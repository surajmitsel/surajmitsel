## map <> ##
- map are associative container that store element with key,value
- No two mapped values can have same key values.
- Key values are sorted while inserting and no duplicate key value.
```cpp
int main(){
    map<int,int> temp;
    temp.insert(pair<int,int>(1,40));
    temp.insert(pair<int,int>(2,30));
    temp.insert(pair<int,int>(3,60));
    temp.insert(pair<int,int>(4,30));
    temp.insert(pair<int,int>(5,20));
    temp.insert(pair<int,int>(6,50));
    temp.insert(pair<int,int>(7,10));

    map<int,int> :: iterator itr;
    for(itr = temp.begin(); itr != temp.end(); itr++){
        cout << itr->first "," << itr->second <<endl;
    }

    //assign value from temp to temp1
    map<int,int> temp1(temp.begin(), temp.end());

    // remove key 4 from temp1
    int num = temp1.erage(4);
    cout << "removed key 4 value = " << num << endl <<;

    // remove all element upto key = 3 in temp1 so less than 3
    temp1.erage(temp1.begin(),temp1.find(3)); //20,50,10
}
```

```cpp
int main(){
    map<char,int> myMap;
    myMap.insert(pair<char,int>('a',100));
    myMap.insert(pair<char,int>('b',200));
    map<char,int> :: interator itr = myMap.begin();    
    myMap.insert(itr,pair<char,int>('c',300)); // its an hint
    itr = myMap.find('z'); // O(log n)

    for(itr = myMap; itr != myMap.end(); itr++){
        cout <<(*itr).first << "," << (*itr).second << endl; 
    }
    // OUTPUT
    //a,100
    //b,200
    //c,300
}
```
```cpp
int main(){
    map<char,int> mymap;
    map<char,int> :: interator itr;
    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['f'] = 60;
    mymap['g'] = 70;

    itr = mymap.find('b');
    mymap.erase(itr);
    mymap.erase('c'); // erage by ket
    itr = mymap.erase('e');
    mymap.erase(itr,mymap.end()); // erase by range

    for(auto &i: mymap){
        cout << i.first << "," << i.second << endl; 
    }
    //output
    //a,10
    //b,20
}
```
```cpp
int main(){
    map<char,int> mymap;
    map<char,int>::key_compare mycomp = mymap.key_comp();
    mymap['a'] = 100;
    mymap['b'] = 200;
    mymap['c'] = 300;
    map<char,int> :: interator itr;
    itr = mymap.begin();
    highest = mymap.rbegin()->first;

    do{
        cout << *itr->first, itr->second << endl;
    }while(mycomp((*itr).first, highest));
}

```

