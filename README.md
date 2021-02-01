# Flight Planner

This is a programming assignment for SMU's CS 2341 (Data Structures) class. 

It is a flight planner that takes in two input files: one for flights between cities and one for requested flight paths. Example input files are below:

`Dallas|Austin|98|47|Spirit`
`Dallas|Austin|98|59|American`
`Austin|Houston|95|39|United`
`Dallas|Houston|101|51|Spirit`
`Austin|Chicago|144|192|American`

The program uses this input to create Flight objects, containing the origin and destination cities, flight cost, and flight time. The flight objects are used to populate an adjacency list.

`Dallas|Houston|T`
`Chicago|Dallas|C`

Request objects are created from this input file. For example, the first request is asking the program to find all paths from Dallas to Houston, then order them in ascending order of lowest time taken. 

Once all the requests are created, the program will iterate through each request. Iterative backtracking (implemented with a stack) exhausts all possible paths from origin to destination by traversing the adjacency list. If a path between two cities is found, a Path object is created that stores all flights taken, total costs, and total time. Finally, all paths are sorted and the top three are printed to the terminal.

The Catch2 test-driven development framework was used to develop all classes. Extensive testing was done to ensure that everything worked as intended before implementing the iterative backtracking solution.
