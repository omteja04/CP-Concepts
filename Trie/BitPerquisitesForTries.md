<!--
  Author: omteja04
  Created on: 27-09-2024 15:19:46
  Description: BitPerquisitesForTries
-->

Num = 9
Stored in 32-bit
| 31 | 30 | ... | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 0 | ... | 1 | 0 | 0 | 1 |

To have a larger number we need to have the the set bit at the indices form left side.

# XOR

1 ^ 1 = 0
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1

if there are even number of 1s &rarr; 0
if there are odd number of 1s &rarr; 1

# To check a bit is set or not

9 &rarr; 0000...1001

to check whether the 3rd (index - 3) bit is 1 or not
`9 >> 3` results 000000...01
now do the AND operation
`(9 >> 3) & 1`results whether the 3rd (index - 3) bit is set or not.

`(num >> i) & 1` results the _ith_ bit set or not set

# Turning on a set bit

9 &rarr; 0000...01001

To turn on the 2nd bit (i = 2)
We need to do masking

For that initially do:
`1 << 2`
results 000...0001 &rarr; 000...0100

now to turn in on use OR operator

`9 | (1 << 2)` results 000...1101

To turn on the _ith_ bit: `num | (1 << i)`
