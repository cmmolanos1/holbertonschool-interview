#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """ calculate how much water will be retained after it rains.

    Args:
        walls:  list of non-negative integers.

    Returns:
        Integer indicating total amount of rainwater retained.
    """
    if walls is None or walls == []:
        return 0
    if len(walls) == 1:
        return 0

    n = len(walls)
    left = [0] * n

    right = [0] * n
    water = 0

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    for i in range(0, n):
        water += min(left[i], right[i]) - walls[i]

    return water
