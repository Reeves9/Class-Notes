from math import gcd

def water_jug_solution(x, y, t):
    g = gcd(x, y)

    if t > x + y or t % g != 0:
        return ["The targeted volume {} is not achievable with jugs of capacities {} and {}.".format(t, x, y)]

    solution = []
    current_state = (0, 0)

    while current_state != (t, 0) and current_state != (0, t):
        jug_x, jug_y = current_state

        if jug_x == 0:
            solution.append("Fill jug x")
            current_state = (x, jug_y)

        elif jug_y == 0:
            solution.append("Fill jug y")
            current_state = (jug_x, y)

        elif jug_x > 0 and jug_y < y:
            remaining = x - jug_x
            transfer = min(jug_x, y - jug_y)
            solution.append(f"Pour {transfer} units from jug x to jug y")
            current_state = (jug_x - transfer, jug_y + transfer)

        elif jug_y > 0 and jug_x < x:
            remaining = y - jug_y
            transfer = min(jug_y, x - jug_x)
            solution.append(f"Pour {transfer} units from jug y to jug x")
            current_state = (jug_x + transfer, jug_y - transfer)

        elif jug_x > 0:
            solution.append("Empty jug x")
            current_state = (0, jug_y)

        elif jug_y > 0:
            solution.append("Empty jug y")
            current_state = (jug_x, 0)

    return solution

x = 3
y = 5
t = 4
solution = water_jug_solution(x, y, t)
for step in solution:
    print(step)