#!/usr/bin/python3
"""
Log Parsing
"""
import sys

counter = 1
sum_size = 0

status_dir = {200: 0,
              301: 0,
              400: 0,
              401: 0,
              403: 0,
              404: 0,
              405: 0,
              500: 0}

try:
    for line in sys.stdin:
        ln = line.replace('\n', ' ').split()
        status = int(ln[-2])
        size = int(ln[-1])
        # print("Status: {}, Size: {}".format(status, size))

        sum_size += size
        status_dir[status] += 1

        if counter % 10 == 0:
            print("File size: {}".format(sum_size))
            for key in sorted(status_dir.keys()):
                if status_dir[key] != 0:
                    print("{}: {}".format(key, status_dir[key]))

        counter += 1

except Exception:
    pass

finally:
    print("File size: {}".format(sum_size))
    for key in sorted(status_dir.keys()):
        if status_dir[key] != 0:
            print("{}: {}".format(key, status_dir[key]))
