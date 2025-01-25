import random
import time

class VacuumCleanerAgent:
    def __init__(self, environment_size):
        self.environment_size = environment_size
        self.environment = [['clean' for _ in range(environment_size)] for _ in range(environment_size)]
        self.agent_position = (0, 0)
        self.obstacle_columns = set()

    def place_obstacles_and_dirt(self, num_obstacles, num_dirt):
        for _ in range(num_obstacles):
            self.place_random_item('obstacle')

        for _ in range(num_dirt):
            self.place_random_item('dirt')

    def place_random_item(self, item):
        while True:
            row = random.randint(0, self.environment_size - 1)
            col = random.randint(0, self.environment_size - 1)

            if item == 'obstacle' and col in self.obstacle_columns:
                continue

            if self.environment[row][col] == 'clean':
                self.environment[row][col] = item

                if item == 'obstacle':
                    self.obstacle_columns.add(col)

                break

    def print_environment(self):
        for i, row in enumerate(self.environment):
            for j, cell in enumerate(row):
                if (i, j) == self.agent_position:
                    print('A', end=' ')
                else:
                    print(cell[0], end=' ')
            print()
        print()

    def clean(self):
        while True:
            self.print_environment()
            time.sleep(0.5)  # Add a delay for better visualization
            self.clean_current_cell()
            if self.is_goal_reached():
                print("Goal reached. Cleaning complete.")
                break

            dirt_position = self.find_nearest_dirt()
            if dirt_position:
                self.move_towards_dirt(dirt_position)
            else:
                self.move_randomly()

    def clean_current_cell(self):
        row, col = self.agent_position
        if self.environment[row][col] == 'dirt':
            print("Cleaning dirt at position", self.agent_position)
            self.environment[row][col] = 'clean'

    def is_goal_reached(self):
        for row in self.environment:
            if 'dirt' in row:
                return False
        return True

    def find_nearest_dirt(self):
        row, col = self.agent_position

        # Check left
        if col > 0 and self.environment[row][col - 1] == 'dirt':
            return (row, col - 1)
        # Check right
        if col < self.environment_size - 1 and self.environment[row][col + 1] == 'dirt':
            return (row, col + 1)
        # Check up
        if row > 0 and self.environment[row - 1][col] == 'dirt':
            return (row - 1, col)
        # Check down
        if row < self.environment_size - 1 and self.environment[row + 1][col] == 'dirt':
            return (row + 1, col)

        return None

    def move_towards_dirt(self, dirt_position):
        target_row, target_col = dirt_position
        current_row, current_col = self.agent_position

        if current_row < target_row:
            self.agent_position = (current_row + 1, current_col)
        elif current_row > target_row:
            self.agent_position = (current_row - 1, current_col)
        elif current_col < target_col:
            self.agent_position = (current_row, current_col + 1)
        elif current_col > target_col:
            self.agent_position = (current_row, current_col - 1)

    def move_randomly(self):
        row, col = self.agent_position
        possible_moves = []

        # Check left
        if col > 0 and self.environment[row][col - 1] != 'obstacle':
            possible_moves.append((-1, 0))
        # Check right
        if col < self.environment_size - 1 and self.environment[row][col + 1] != 'obstacle':
            possible_moves.append((1, 0))
        # Check up
        if row > 0 and self.environment[row - 1][col] != 'obstacle':
            possible_moves.append((0, -1))
        # Check down
        if row < self.environment_size - 1 and self.environment[row + 1][col] != 'obstacle':
            possible_moves.append((0, 1))

        # Randomly choose a valid move
        if possible_moves:
            move = random.choice(possible_moves)
            self.agent_position = (row + move[1], col + move[0])

if __name__ == "__main__":
    agent = VacuumCleanerAgent(6)
    agent.place_obstacles_and_dirt(5, 5)
    agent.clean()
