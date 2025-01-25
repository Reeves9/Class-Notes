import tkinter as tk
from collections import deque
import random

class Node:
    def __init__(self, state, parent=None, move=None):
        self.state = state
        self.parent = parent
        self.move = move

    def __eq__(self, other):
        return self.state == other.state

    def __hash__(self):
        return hash(str(self.state))

def find_blank(state):
    for i in range(9):
        if state[i] == 0:
            return i

def get_moves(state):
    moves = []
    blank = find_blank(state)
    if blank not in [0, 1, 2]:
        moves.append(-3)
    if blank not in [6, 7, 8]:
        moves.append(3)
    if blank not in [0, 3, 6]:
        moves.append(-1)
    if blank not in [2, 5, 8]:
        moves.append(1)
    return moves

def make_move(state, move):
    blank = find_blank(state)
    new_state = state[:]
    new_state[blank], new_state[blank + move] = new_state[blank + move], new_state[blank]
    return new_state

def solve_puzzle(initial_state, algorithm):
    start_node = Node(initial_state)
    if algorithm == "DFS":
        frontier = [start_node]
    else:
        frontier = deque([start_node])
    explored = set()
    steps = []

    while frontier:
        if algorithm == "DFS":
            node = frontier.pop()
        else:
            node = frontier.popleft()

        if node.state == [0, 1, 2, 3, 4, 5, 6, 7, 8]:
            solution = []
            while node.parent:
                solution.append(node.move)
                node = node.parent
            solution.reverse()
            return solution, steps

        explored.add(node)
        steps.append(node.state)

        for move in get_moves(node.state):
            new_state = make_move(node.state, move)
            child_node = Node(new_state, node, move)
            if child_node not in explored:
                if algorithm == "DFS":
                    frontier.append(child_node)
                else:
                    frontier.append(child_node)

    return None, steps

def draw_puzzle(canvas, state):
    canvas.delete("all")
    canvas.create_rectangle(10, 10, 310, 310, outline="black")
    for i in range(9):
        x1 = (i % 3) * 100 + 10
        y1 = (i // 3) * 100 + 10
        x2 = x1 + 100
        y2 = y1 + 100
        canvas.create_rectangle(x1, y1, x2, y2, outline="black")
        if state[i] != 0:
            canvas.create_text((x1 + x2) // 2, (y1 + y2) // 2, text=str(state[i]), font=("Arial", 36))

def animate_solution(canvas, solution, initial_state, delay=500):
    state = initial_state
    draw_puzzle(canvas, state)
    root.update()
    for move in solution:
        blank = find_blank(state)
        state[blank], state[blank + move] = state[blank + move], state[blank]
        draw_puzzle(canvas, state)
        root.update()
        root.after(delay)

def generate_valid_state():
    state = list(range(9))
    random.shuffle(state)
    inversions = sum(state[i] > state[i + 1] for i in range(8) if state[i] and state[i + 1])
    if (inversions % 2) == 0:
        return state
    else:
        state[0], state[1] = state[1], state[0]
        return state

def solve_button_click():
    initial_state = generate_valid_state()
    for entry, value in zip(entries, initial_state):
        entry.delete(0, tk.END)
        entry.insert(0, str(value))

    algorithm = algorithm_var.get()
    solution, steps = solve_puzzle(initial_state, algorithm)
    if solution is None:
        result_label.config(text="No solution found")
    else:
        result_label.config(text=f"Solution found in {len(solution)} moves")
        animate_solution(canvas, solution, initial_state)

root = tk.Tk()
root.title("8-Puzzle Solver")

entries = [tk.Entry(root, width=2, font=("Arial", 16)) for _ in range(9)]
for i in range(9):
    row = i // 3
    col = i % 3
    entries[i].grid(row=row, column=col)

canvas = tk.Canvas(root, width=320, height=320)
canvas.grid(row=0, column=3, rowspan=3, padx=10)

solve_button = tk.Button(root, text="Solve", command=solve_button_click)
solve_button.grid(row=3, column=0, columnspan=3, pady=10)

result_label = tk.Label(root, text="")
result_label.grid(row=4, column=0, columnspan=3)

algorithm_var = tk.StringVar()
algorithm_var.set("BFS")
dfs_radio = tk.Radiobutton(root, text="DFS", variable=algorithm_var, value="DFS")
dfs_radio.grid(row=5, column=0)
bfs_radio = tk.Radiobutton(root, text="BFS", variable=algorithm_var, value="BFS")
bfs_radio.grid(row=5, column=1)

root.mainloop()