# Truth table for the given problem
month = [
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111",
]
days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30]
output = [1 if days_in_month[i] == 30 else 0 for i in range(len(month))]

# Creating a dictionary to map month to its output
month_to_output = dict(zip(month, output))

# Boolean expression in SIGMA-M form
sigma_m = ""
for i in range(len(month)):
    if output[i] == 1:
        sigma_m += f"{month[i]} + "

sigma_m = sigma_m[:-3]

# Simplifying using K-map
kmap = [[0 for _ in range(4)] for _ in range(4)]
for i in range(len(month)):
    binary_month = list(map(int, month[i]))
    kmap[binary_month[0]][binary_month[1]] = output[i]

# Finding minterms
minterms = []
for i in range(4):
    for j in range(4):
        if kmap[i][j] == 1:
            minterms.append(f"{i}{j}")

# Simplifying using K-map
simplified_expression = ""
for minterm in minterms:
    if minterm[0] == minterm[1]:
        simplified_expression += f"A' + "
    else:
        simplified_expression += f"A{minterm[0]} + "

simplified_expression = simplified_expression[:-3]

# Implementing simplified expression using NAND gates
nand_implementation = ""
for term in simplified_expression.split(" + "):
    if len(term) == 1:
        nand_implementation += f"NAND(A, A)"
    else:
        nand_implementation += f"NAND(NAND({term[0]}, {term[1]}), NAND({term[0]}, {term[1]}))"

print("Truth table:")
print(f"Month\tDays\tOutput")
for i in range(len(month)):
    print(f"{month[i]}\t{days_in_month[i]}\t{output[i]}")

print(f"\nSigma-M form: {sigma_m}")
print(f"\nSimplified expression: {simplified_expression}")
print(f"\nNAND implementation: {nand_implementation}")