import torch
import string
import random
import multiprocessing as mp

def generate_random_string(length):
    device_id = torch.cuda.current_device()
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(length)), device_id

def check_string(string_tuple, target_string):
    string_to_check = string_tuple[0]
    return string_to_check == target_string, string_tuple[1]

def generate_strings(num_processes):
    target_string = "hello world"
    pool = mp.Pool(processes=num_processes)
    pool_outputs = []

    for i in range(num_processes):
        device_id = i % torch.cuda.device_count()
        torch.cuda.set_device(device_id)
        pool_outputs.append(pool.apply_async(generate_random_string, args=(len(target_string),)))

    pool.close()
    pool.join()

    for p in pool_outputs:
        result, device_id = p.get()
        if result == target_string:
            print(f"Found string {result} on device {device_id}.")
            return
        else:
            print(f"Device {device_id} failed to find string {result}.")
