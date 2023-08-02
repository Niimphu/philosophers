# Philosophers
## Introduction
In the philosophers project, we try to solve the classic coding problem of dining philosophers trying to share resources. The concepts explored in philosophers are multithreading, data races, and protecting those variables with mutexes.

### Multithreading
Normally, a program runs linearly, one step after another. However, multithreading can be used to allow the program to perform many operations in parallel at the same time, at the cost of increased processing power. This can greatly increase the performance of a program and can the ease of which some operations can be performed.

Utilising multithreading does not come without problems. When two or more threads attempt to access and modifiy a variable concurrently without sufficient protection, it can result in undefined and unpredictable behaviour occuring. This is called a "race condition" or "data race".

To prevent data races, shared variables need to be protected. One way of achieving this is with a "mutex", which stands for "mutual exclusion". They restrict access to critial sections of code by only allowing one thread to access them at any one time. Using a mutex looks something like this:

```

```
