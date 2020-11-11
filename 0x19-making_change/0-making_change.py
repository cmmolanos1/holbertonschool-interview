#!/usr/bin/python3
"""
make change
"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.

    Args:
        coins (list): he values of the coins in your possession.
        total (int): the value to reach with coins.

    Returns:
        0: if total is 0 or less
        -1: If total cannot be met by any number of coins you have
    """
    if total < 0:
        return 0

    T = [0] + [float('inf')] * (total)

    for i in range(total + 1):
        for c in range(len(coins)):
            if i - coins[c] >= 0:
                res = T[i - coins[c]]

                if res != float('inf'):
                    T[i] = min(T[i], res + 1)

    return T[total] if T[total] != float('inf') else -1
