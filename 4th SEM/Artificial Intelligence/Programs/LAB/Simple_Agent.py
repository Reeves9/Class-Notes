import random
import matplotlib.pyplot as plt
import numpy as np

DIRT = 1
OBSTACLE = 2
CLEAN = 0

grid = np.random.choice([DIRT, OBSTACLE, CLEAN], size=(5, 5), p=[0.4, 0.2, 0.4])

agent_row = random.randint(0, 4)
agent_col = random.randint(0, 4)

def visualize_grid():
    plt.figure(figsize=(5, 5))
    plt.imshow(grid, cmap='binary')
    plt.plot(agent_col, agent_row, 'rX', markersize=10)
    plt.show()

def agent_traverse():
    global agent_row, agent_col

    dirt_cells = []
    for row_offset in [-1, 0, 1]:
        for col_offset in [-1, 0, 1]:
            if row_offset == col_offset == 0:
                continue
            new_row = agent_row + row_offset
            new_col = agent_col + col_offset
            if (0 <= new_row < 5 and 0 <= new_col < 5 and
                grid[new_row, new_col] == DIRT):
                dirt_cells.append((new_row, new_col))

    if dirt_cells:
        target_row, target_col = random.choice(dirt_cells)
        move_row = target_row - agent_row
        move_col = target_col - agent_col
    else:
        move_row = random.choice([-1, 0, 1])
        move_col = random.choice([-1, 0, 1])

    new_row = agent_row + move_row
    new_col = agent_col + move_col

    if (0 <= new_row < 5 and 0 <= new_col < 5 and
        grid[new_row, new_col] != OBSTACLE):

        agent_row = new_row
        agent_col = new_col

        if grid[agent_row, agent_col] == DIRT:
            grid[agent_row, agent_col] = CLEAN

    visualize_grid()

visualize_grid()

num_steps = 20
for _ in range(num_steps):
    agent_traverse()