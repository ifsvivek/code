import numpy as np

# Allocate a large array of integers
array_size = 10**8  # 100 million elements
large_array = np.zeros(array_size, dtype=np.int32)

# Create a list of objects that consume memory
object_list = []
for _ in range(10**6):  # Create 1 million objects
    object_list.append([0] * (10**4))  # Each object has 10,000 elements

# Keep the program running to maintain memory usage
while True:
    pass
