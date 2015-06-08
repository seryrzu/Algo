
#                         RECURRENT EQUATIONS


There exist three popular methods for solving recurrents:
  
  1. Substitution method 
  2. Iteration method 
  3. Master theorem
  
Substitution method
-------------------

Main idea: guess solution and proove with means of induction.

_Example_: $T(n) = 2 T( \lfloor n/2 \rfloor ) + n$.
           Let $T(n) = O(n \log n)$ is true for $\lfloor n/2 \rfloor$.
           This yelds:
             $$T(n) \le 2(c \lfloor n/2 \rfloor \log(\lfloor n/2 \rfloor) + n
                    \le c n \log(n/2) + n = cn \log n - cn \log 2 + n = 
                    cn \log n - cn + n$$

Iteration method
----------------

Main idea: convert recurrent into sum. ( _TODO_: Wut?)


Master theorem
--------------

The most useful recurrents often look like: $T(n) = aT(n/b) + f(n)$. Where
$a \ge 1, b > 1$ are const. And $f > 0$ is continious and monotonic. 

_Example_: `MergeSort`: $a = b = 2$, $f = \Theta(n)$.

_Note_: rounding (flooring) does not matter.

__Master theorem__: For such equations this is true:
     
  1. If $f = O(n^{\log_b a - \varepsilon})$ for some $\varepsilon > 0$ than 
        $T = \Theta(n^{\log_b a})$.

  2. If $f = \Theta(n^{\log_b a})$ then 
        $T = \Theta(n^{\log_b n} \log_2 n n)$.

  3. If  $f = \Omega(n^{\log_b a} + \varepsilon)$ for some $\varepsilon > 0$
     and $a f(n/b) \le c f(n)$ for some $c < 1$ and $n > n_0$ than
         $T(n) = \Theta(f(n))$.

See also
--------

  * [Wikipedia](http://en.wikipedia.org/wiki/Master_theorem#Generic_form)
  * [StackOverflow](http://cs.stackexchange.com/questions/9390/ho$w-to-the-examples-for-using-the-master-theorem-in-cormen-work)
