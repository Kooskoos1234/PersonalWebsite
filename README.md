This project is in two components, each of which contain slight variations on the same three subcomponents.
Firstly, the main code for the three subcomponents was built in C++. 
  I implemented 4 sorting algorithms - bubbleSort, selectionSort, quickSort, and mergeSort - and a function to time all of them, as well as C++'s builtin introSort, sorting the same random array.
  I implemented a simple prime number sieve to find prime numbers, as well as to store it in a .csv, read that .csv, and use the list of prime numbers to factorize a number less than or equal to the largest known prime squared. 
  I implemented an function to calculate the sum of any number of 2D vectors, given either in magnitude @ degree form or in (x, y) form.
These components could only be interacted with through console, which is not ideal, but they did what they needed to quite effectively.
Secondly, I used the emscripten API to convert some of this code to WASM, then glued it together with Javascript to make a functioning, if unpolished, website. 
  The website could use and benchmark the 5 sorting algorithms correctly for any array with user defined length, minimum, or maximum, but could only sort numbers, to not overcomplicate UI, and was a fair bit slower. 
  The website could find any prime under a significantly lower threshold, as it did not read primes from the file, but rather a much shorter, predefined list
  The website could add any pair of vectors, but only in magnitude @ angle form, as allowing N vector addition or permitting both magnitude @ angle and (x, y) forms would overcomplicate the UI
These limitations are significant, but due to the time constraints in making this project, I had to restrict the scope of each component to the smaller bits visible in that website.
Worth noting that the website as provided in the HTML, JS, and WASM files will not work locally; they must be hosted on a server to function properly, and I am not currently hosting one that could be used for this. 
