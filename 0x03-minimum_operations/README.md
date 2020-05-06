# Minimum Operations 

In a text file, there is a single character `H`. Your text editor can execute only two operations in this file: `Copy All` and `Paste`. Given a number `n`, write a method that calculates the fewest number of operations needed to result in exactly `n` `H` characters in the file.

## Example

n = 9

`H` => `Copy All` => `Paste` => `HH` => `Paste` =>`HHH` => `Copy All` => `Paste` => `HHHHHH` => `Paste` => `HHHHHHHHH`

Number of operations: `6`

```python
>>> n = 4
>>> print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))
Min number of operations to reach 4 characters: 4
>>> n = 12
>>> print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))
Min number of operations to reach 12 characters: 7
```