# First duplicate

Given an array a that contains only numbers in the range from `1` to
`a.length`, find the only duplicate number. If there are no such
elements, return -1.

### Example

* For a = [2, 1, 3, 4, 3], the output should be
    ```
    one_duplicate(a) = 3.
    ```

* For a = [2, 4, 3, 5, 1], the output should be
    one_duplicate(a) = -1.

### Input/Output

* [input] array.integer a
    ```
    Guaranteed constraints:
    1 ≤ a.length ≤ 105,
    1 ≤ a[i] ≤ a.length.
    ```
* [output] integer
    The duplicated element. If there are no such elements, return -1.
