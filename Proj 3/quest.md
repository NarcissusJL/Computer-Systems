The asymptotic time complexity of the heap sort algorithm on an array that is already
sorted is $O(n\log{n})$. In "buildHeap()" it will do nothing. Each time pop the top of the heap the time complexity is $O(\log{n})$.  
The asymptotic time complexity on an array that is in reverse order is $O(n\log{n})$. The reason is as same as above.  
The best case is $O(n)$ and the numbers of input should all be equal.