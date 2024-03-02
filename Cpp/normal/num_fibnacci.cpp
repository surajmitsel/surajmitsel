#include <iostream>
#include <type_traits>
using namespace std;
// METHOD1
void fibnacci(int num){
    int a = 1, b = 0 , c = 0;
    while(c <= num){
        c = a + b;
        a = b;
        b = c; 
        std::cout << b << ",";
    }
}

// METHOD2
int fib(int x) {
   //cout << x << "|" <<endl;
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}

int main(){
    
    // method1: it will print next number after 20
    fibnacci(20);
    
    // method2: it will print next 20 iteration 
    int i = 0; 
    int x = 20;
    for(int i = 0; i < x; i++){
        std::cout << fib(i) << ",";
        i++;
    }
    return 0;
}