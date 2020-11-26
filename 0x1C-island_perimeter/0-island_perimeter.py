#!/usr/bin/python3
"""
Island perimeter
"""


def grid_margin(m):
    """Create a margin of 0s

    Args:
        m (list): 2D list

    Returns:
        the padded list
    """
    new_m = [l for l in m]

    for l in new_m:
        l.append(0)
        l.insert(0, 0)

    new_m.append([0] * len(new_m[0]))
    new_m.insert(0, [0] * len(new_m[0]))
    return new_m


def island_perimeter(grid):
    """calculates perimeter of the island described in grid.

    Args:
        grid: list of integers

    Returns:
        the perimeter
    """
    perimeter = 0

    grid_1 = grid_margin(grid)

    for row in range(len(grid_1)):
        for col in range(len(grid_1[row])):

            if grid_1[row][col] == 1:
                if grid_1[row - 1][col] == 0:
                    perimeter += 1

                if grid_1[row + 1][col] == 0:
                    perimeter += 1

                if grid_1[row][col - 1] == 0:
                    perimeter += 1

                if grid_1[row][col + 1] == 0:
                    perimeter += 1

    return perimeter
