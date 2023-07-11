import numpy as np
import psutil

def use_up_ram():
    max_memory_limit = 100  # Maximum memory limit in megabytes
    allocated_memory = 0
    arrays = []
    array_size = (1024, 1024)  # Initial array size

    while True:
        try:
            arr = np.zeros(array_size, dtype=np.float64)
            allocated_memory += arr.nbytes / (1024 * 1024)  # Calculate memory usage in megabytes
            arrays.append(arr)

            if allocated_memory >= max_memory_limit:
                allocated_memory = 0

        except MemoryError:
            # Reduce the array size by half if a MemoryError occurs
            array_size = tuple(dim // 2 for dim in array_size)
            print(f"Reduced array size to {array_size}")

        # Check if available memory is below the threshold
        mem_available = psutil.virtual_memory().available / (1024 * 1024)
        if mem_available < max_memory_limit:
            break

if __name__ == "__main__":
    print("This program rapidly consumes a large amount of RAM.")
    print("Press Ctrl+C to stop.")

    try:
        use_up_ram()
    except KeyboardInterrupt:
        print("\nProgram stopped by the user.")
