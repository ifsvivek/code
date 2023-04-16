import torch
from multiprocessing import Pool

def generate_random_string(seed):
    chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"
    string_length = 12
    device_ids = list(range(torch.cuda.device_count()))
    torch.cuda.set_device(device_ids[seed % len(device_ids)])
    random_string = torch.randint(len(chars), size=(string_length,), device=f'cuda:{device_ids[seed % len(device_ids)]}')
    return "".join(chars[i] for i in random_string)

def check_hello_world(string):
    return string == "Hello World!"

def generate_strings(num_processes):
    pool = Pool(processes=num_processes)
    num_generated = 0
    while True:
        seeds = range(num_generated, num_generated + num_processes)
        random_strings = pool.map(generate_random_string, seeds)
        for random_string in random_strings:
            if check_hello_world(random_string):
                pool.terminate()
                print("Found 'Hello World!'")
                return
        num_generated += num_processes

if __name__ == '__main__':
    if not torch.cuda.is_available():
        print("CUDA is not available on this machine.")
    else:
        print("This program generates random strings and checks if they say 'Hello World!'")
        print("It may take a while to find a string that says 'Hello World!'")

        num_processes = 8
        generate_strings(num_processes)