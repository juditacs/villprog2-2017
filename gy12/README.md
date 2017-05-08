~~~
$ g++ exception_example.cpp -Wall -ansi -o exc

$ ./exc 80
Noisy 3 created
Noisy 1 created
Noisy 2 created
Noisy 1 destroyed
Noisy 2 destroyed
Noisy 3 destroyed

$ ./exc 120
Noisy 3 created
Noisy 1 created
Noisy 3 destroyed
out_of_range: Percent cannot be over 100

$ ./exc 1
Noisy 3 created
Noisy 1 created
Noisy 3 destroyed
TooManyFailures: Too many students failed
~~~
