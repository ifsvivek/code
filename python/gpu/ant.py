import numpy as np
import matplotlib.pyplot as plt

# Parameters
N = 200
n_ants = 20
n_slime = 50
p_evaporate = 0.05
p_deposit = 0.1
p_move = 0.8

# Initialize grid
grid = np.zeros((N, N))

# Initialize ants
ants = []
for i in range(n_ants):
    ant = {'x': np.random.randint(N), 'y': np.random.randint(N)}
    ants.append(ant)

# Initialize slime
slime = []
for i in range(n_slime):
    s = {'x': np.random.randint(N), 'y': np.random.randint(N)}
    slime.append(s)

# Simulation loop
for t in range(1000):

    # Update slime
    for s in slime:
        if np.random.rand() < p_evaporate:
            grid[s['x'], s['y']] = 0
        elif np.random.rand() < p_deposit:
            grid[s['x'], s['y']] += 1

    # Update ants
    for ant in ants:

        # Move ant
        if np.random.rand() < p_move:
            dx, dy = np.random.randint(-1, 2, size=2)
            ant['x'] = (ant['x'] + dx) % N
            ant['y'] = (ant['y'] + dy) % N

        # Leave slime trail
        grid[ant['x'], ant['y']] += 1

    # Plot grid
    plt.clf()
    plt.imshow(grid, cmap='Greys', vmin=0, vmax=10)
    plt.scatter([ant['x'] for ant in ants], [ant['y'] for ant in ants], color='red', marker='o')
    plt.scatter([s['x'] for s in slime], [s['y'] for s in slime], color='green', marker='o')
    plt.title(f"Time = {t}")
    plt.pause(0.01)

plt.show()
