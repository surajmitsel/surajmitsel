#include <iostream>
#include <type_traits>
#include <unordered_map>
using namespace std;
// METHOD1
void fib_loop(int num){
    int a = 1, b = 0 , c = 0;
    while(c <= num){
        c = a + b;
        a = b;
        b = c; 
        std::cout << b << ",";
    }
}

// METHOD2
int fib_rec(int x) {
   if(x < 2) {
      return x ;
   }else {
      return fib_rec(x-1)+fib_rec(x-2) ;
   }
}
// METHOD 3: Bottom-up approach
int fib_dp(int num){
    if(num < 2){
        return num;  // 0,1,1,2
    }
    
    vector<int> dp(num+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= num; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

int fib_dp_rec(unordered_map <int,int> &dp , int num)
{
    if(dp.find(num) != dp.end()){
        return dp[num];
    }
    int result;
    if(num < 2)
        result = num;
    else 
        result = fib_dp_rec(dp,num-1) +  fib_dp_rec(dp,num-2);
    
    dp[num] = result;
    return result;
}

int main(){
    
    // method1: it will print next number after 20
    fib_loop(20);
    cout << endl;
    
    // method2: it will print next 20 iteration 
    int x = 20;
    for(int i = 0; i < x; i++){
        std::cout << fib_rec(i) << ",";
        i++;
    }
    cout << endl;
    
    // Method3
    cout << fib_dp(8) << endl; //0,1,1,2,3,5,8,13,21 (num value start from 0)

    // Method4
    int num = 8;
    unordered_map<int,int> dp; // <index,value>
    cout << fib_dp_rec(dp,num) << endl;

    return 0;
}
/*
1,1,2,3,5,8,13,21,
0,1,3,8,21,55,144,377,987,2584,
21
21
*/