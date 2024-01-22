import random
import matplotlib.pyplot as plt
import pygame
import random

class VacuumAgent:
    def __init__(self, grid_size):
        self.grid_size = grid_size
        self.grid = [[random.choice(['clean', 'obstacle', 'dirt']) for _ in range(grid_size)] for _ in range(grid_size)]
        self.visited = set()
        self.position = (0, 0)
        self.movements = [(0, 0)]

    def display_grid(self):
        for row in self.grid:
            print(" ".join(row))
        print()

    def display_movement(self):
        x_values, y_values = zip(*self.movements)
        plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')
        plt.title('Agent Movement')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.grid(True)
        plt.show()

        # Pygame setup
        self.cell_size = 50
        self.screen_size = grid_size * self.cell_size
        pygame.init()
        self.screen = pygame.display.set_mode((self.screen_size, self.screen_size))
        pygame.display.set_caption('Vacuum Agent')

    def display_grid(self):
        self.screen.fill((255, 255, 255))

        for y in range(self.grid_size):
            for x in range(self.grid_size):
                color = (200, 200, 200)  # Default color for clean cells

                if self.grid[y][x] == 'obstacle':
                    color = (0, 0, 0)  # Black for obstacle cells
                elif self.grid[y][x] == 'dirt':
                    color = (255, 0, 0)  # Red for dirt cells

                pygame.draw.rect(self.screen, color, (x * self.cell_size, y * self.cell_size, self.cell_size, self.cell_size))

        pygame.draw.rect(self.screen, (0, 255, 0), (self.position[0] * self.cell_size, self.position[1] * self.cell_size, self.cell_size, self.cell_size))

        pygame.display.flip()

    def move_towards_dirt(self):
        x, y = self.position
        possible_moves = []

        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                new_x, new_y = x + dx, y + dy
                if 0 <= new_x < self.grid_size and 0 <= new_y < self.grid_size and (new_x, new_y) not in self.visited:
                    possible_moves.append((new_x, new_y))

        dirt_moves = [(dx, dy) for dx, dy in possible_moves if self.grid[dy][dx] == 'dirt']
        if dirt_moves:
            return random.choice(dirt_moves)
        else:
            return random.choice(possible_moves)

    def clean_dirt(self):
        x, y = self.position
        self.grid[y][x] = 'clean'

    def move(self):
        next_move = self.move_towards_dirt()
        self.visited.add(self.position)
        self.position = next_move
        self.clean_dirt()
        self.movements.append(next_move)

if __name__ == "__main__":
    grid_size = 5
    vacuum_agent = VacuumAgent(grid_size)

    for _ in range(10):
        vacuum_agent.display_grid()
        vacuum_agent.move()

    vacuum_agent.display_grid()
    vacuum_agent.display_movement()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        vacuum_agent.display_grid()
        pygame.time.delay(500)  # Delay to slow down the visualization
        vacuum_agent.move()

    pygame.quit()

