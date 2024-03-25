### std::execution
std::execution is a feature introduced in C++17 as part of the Parallelism TS (Technical Specification), which provides a mechanism for specifying execution policies for parallel algorithms in the Standard Library. It allows developers to control the execution characteristics of algorithms, such as parallelism, concurrency, and execution semantics.

### It defines 3 execution policies:

#### 1. std::execution::seq (Sequential Execution):
- Specifies sequential execution of the algorithm.
- The algorithm is executed serially on a single thread.
- This policy is equivalent to the behavior of traditional sequential algorithms.

#### 2. std::execution::par (Parallel Execution):
- Specifies parallel execution of the algorithm.
- The algorithm may be executed concurrently on multiple threads.
- The Standard Library implementations may utilize multithreading or other parallelism mechanisms to execute the algorithm in parallel.
- The number of threads and specific parallelization strategies may vary depending on the implementation and the underlying hardware.

#### 3. std::execution::par_unseq (Parallel and Vectorized Execution):
- Specifies parallel and vectorized execution of the algorithm.
- The algorithm may be executed concurrently on multiple threads, and within each thread, vectorization may be applied to exploit SIMD (Single Instruction, Multiple Data) instructions for optimized performance.
- This policy is suitable for algorithms where both parallelism and vectorization can be leveraged to achieve better performance.
- These execution policies can be used as template arguments with parallel algorithms in the Standard Library, such as std::for_each, std::transform, std::sort, etc., to specify the desired execution characteristics. For example:

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {5, 2, 7, 1, 8};

    // Sort the vector in parallel
    std::sort(std::execution::par, vec.begin(), vec.end());

    return 0;
}
```
In this example, std::sort is invoked with the std::execution::par execution policy, indicating that the sorting algorithm should be executed in parallel. The actual parallelization strategy and the number of threads used for parallel execution may vary depending on the implementation and runtime environment.