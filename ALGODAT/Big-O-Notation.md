# Big-O-Notation

#### niklas brandtner 05.03.2024

## A1)

### 1)	O(10n)

- `10n` wird vereinfacht zu `O(n)` da alle konstanten faktoren und summanden ignoriert werden da sie bei großen Eingabegrößen weniger relevant sind.

### 3)	O(14n³−3n²+ 10) = ?

- `O(14n³−3n²+ 10) = ?` wird vereinfacht zu `O(1)` also eine konstante Zeitkomplexität. Unabhängig vom Wert von n bleibt die Zeitkomplexität konstant. Da der Wert von sin(n) zwischen -1 und 1 schwankt, bleibt der Ausdruck 3 + 2 ∙ sin(n) immer in einem konstanten Bereich, unabhängig vom Wert von n.

### 5)	O(2n² + 3n+ 3) = ?

- `O(2n² + 3n+ 3) = ?` wird vereinfacht zu `O(n²)` da dies der dominante Term des Ausdrucks ist.

### 7)	O(4n²	 · log(n) + 2n · (log(n)))³ = ?

- `O(4n² · log(n) + 2n · (log(n)))³ = ?` wird vereinfacht zu `O((n²*log(n))^3)` oder `O(n^6*(log(n))^3)` da der Ausdruck `4n²*log(n)`dominanter ist als `2n*log(n)`

### 9)	O(4n · (-2 + 3n) · (n - log(n)) / n) = ?

- `O(4n · (-2 + 3n) · (n - log(n)) / n) = ?` wird vereinfacht zu `O(n^2)`:

  - The given expression is:
    $$
    \begin{align*}
    O\left\{4n \cdot (-2 + 3n) \cdot \frac{n - \log(n)}{n}\right\}
    \end{align*}
    $$
    

    We can simplify the expression by removing n from the numerator:
    $$
    \begin{align*}
    O\left\{4n \cdot (-2 + 3n) \cdot (1 - \frac{\log(n)}{n})\right\}
    \end{align*}
    $$
    
    
    

    This simplifies to:
    $$
    \begin{align*}
    O\left\{4n \cdot (-2 + 3n - \log(n) + \frac{3\log(n)}{n})\right\}
    \end{align*}
    $$
    

    As `n` approaches infinity, the term `3log(n)/n` tends to `0`. So, we can ignore this term for large `n`. Therefore, the simplified time complexity is:
    $$
    \begin{align*}
    O\left\{4n \cdot (-2 + 3n - \log(n))\right\}
    \end{align*}
    $$
    

    This is equivalent to:
    $$
    \begin{align*}
    O\left\{-8n + 12n^2 - 4n\log(n)\right\}
    \end{align*}
    $$
    

    In Big O notation, we only keep the highest order term, and the coefficients are not considered. Therefore, the time complexity of the given expression is:
    $$
    \begin{align*}
    O\left\{n^2\right\}
    \end{align*}
    $$

### Bonus:

O(4n · (-2 + 3n) · (n - log(n)) / n)

```cpp
#include <iostream>
#include <cmath>

void Algorithm(int n) {
    for (int i = 1; i <= 4 * n; ++i) { // outer loop iterates 4n times
        for (int j = 1; j <= -2 + 3 * n; ++j) { // middle loop  iterates (−2+3n) times
            for (int k = 1; k <= n - log(n); ++k) { // inner loop iterates (n−log(n)) times
                for (double l = 0; l < (1.0 / n) * 1000000; ++l) { // innermost loop iterates 1/n
                    // any O(1) Operation here :)
                }
            }
        }
    }
}

int main() {
    int n = 10; // Example value for n
    Algorithm(n);
    return 0;
}
```
