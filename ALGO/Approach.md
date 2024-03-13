
### brute force approach
In dynamic programming, the term "brute force approach" typically refers to 
`solving a problem using a recursive approach without memoization` 
or other optimization techniques.

For example, in the context of computing Fibonacci numbers, 
a brute force approach would involve using a simple recursive function without memoization:

### greedy approach
The greedy approach is a problem-solving strategy where a decision is made at each step based solely on the current best option without regard for the overall consequences. In other words, at each step of the algorithm, the choice that appears to be the most advantageous is selected without considering the future implications.

Here are the key characteristics of the greedy approach:

- `Local Optimal Choice`: At each step, the greedy algorithm selects the locally optimal choice without considering the global picture.

- `No Backtracking`: Once a decision is made, it's never reconsidered or changed. There's no backtracking to revise previous decisions.

- `No Future Consideration`: The algorithm doesn't look ahead to anticipate future steps or optimize the overall solution.

While the greedy approach often yields a suboptimal solution, it can be a powerful tool for solving problems efficiently when the problem has the greedy-choice property. This property ensures that making the locally optimal choice at each step leads to a globally optimal solution.

However, it's important to note that not all problems can be solved using a greedy approach, and applying it to the wrong problem may result in an incorrect solution. It's essential to analyze the problem's characteristics and determine whether the greedy approach is appropriate.

### Backtracking Approach
Backtracking is a problem-solving technique used to systematically search for a solution to a problem by trying various options, backtracking from choices that don't appear to work. It is based on the concept of trial and error.

Here's how the backtracking approach typically works:

- `Systematic Search`: Backtracking involves systematically exploring all possible solutions to a problem. It starts with an initial solution and incrementally builds upon it.

- `Exploration of Choices`: At each step of the search, the algorithm explores all possible choices or options available. It makes a choice and proceeds further until a solution is found or until it determines that the current path cannot lead to a solution.

- `Backtracking`: If the current choice does not lead to a valid solution, the algorithm backtracks to the previous decision point and tries a different choice. This process continues recursively until all possible combinations are explored or until a solution is found.

- `Constraint Satisfaction`: Backtracking is particularly useful for problems that involve constraint satisfaction, 
where each decision must satisfy certain constraints or conditions.

- `Recursive Nature`: Backtracking algorithms often use recursion to explore all possible choices. Recursive calls are made to explore each possible option, and the search space is traversed depth-first.

Backtracking is commonly used to solve problems such as generating all permutations or combinations, solving puzzles like Sudoku or N-Queens, and searching for paths in a graph or tree. It is a powerful technique that allows for efficient exploration of large solution spaces while avoiding redundant computations. However, it can be computationally expensive, especially for problems with a large search space.