#include <iostream>
#include <thread>

// Define a functor class
class MyFunctor {
public:
    // Overload the function call operator ()
    void operator()() {
        std::cout << "Thread is running\n";
    }
};

int main() {
    // Create an instance of the functor class
    MyFunctor myFunctor;

    // Launch a thread using the functor
    std::thread myThread(myFunctor);

    // Wait for the thread to finish execution
    myThread.join();

    return 0;
}


/*
Using a functor to launch a thread in C++ provides several advantages:

- Encapsulation: Functors encapsulate both data and behavior within a single object. 
This can lead to cleaner and more modular code compared to free-standing functions or static member functions.

- Flexibility: Functors can maintain state between function calls because they are objects. 
This allows you to pass parameters to the functor's constructor and use member variables to 
store state information, providing more flexibility than passing parameters to a standalone function.

- Customization: Functors can be customized by overloading the operator() with different parameter 
types or return types, allowing for a wide range of behaviors within the same functor class.

- Reusability: Functors can be reused across different parts of the codebase. Once defined, 
they can be passed to multiple threads or used in other contexts where a callable object is required.

- Compatibility with Standard Library Algorithms: Functors are often used with standard 
library algorithms like std::for_each, std::transform, and std::sort, 
providing a unified interface for performing operations on collections.

- Performance: Depending on the specific scenario, using functors might provide 
performance benefits compared to using lambda functions or free-standing functions. 
Since functors are implemented as classes, the compiler may optimize their usage more effectively.

Overall, using a functor to launch a thread can lead to more maintainable, flexible, 
and efficient code, especially in scenarios where you need to pass state or behavior to the thread function.

*/