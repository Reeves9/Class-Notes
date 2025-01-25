import numpy as np

def input_matrix():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    print(f"Enter the elements of the {rows}x{cols} matrix:")
    matrix = []
    for i in range(rows):
        row = list(map(float, input().split()))
        matrix.append(row)
    return np.array(matrix)

def inverse(matrix):
    try:
        return np.linalg.inv(matrix)
    except np.linalg.LinAlgError:
        return "Matrix is not invertible"

def determinant(matrix):
    return np.linalg.det(matrix)

def multiply_matrices(matrix1, matrix2):
    try:
        return np.dot(matrix1, matrix2)
    except ValueError:
        return "Matrices cannot be multiplied. Check dimensions."

def add_matrices(matrix1, matrix2):
    try:
        return np.add(matrix1, matrix2)
    except ValueError:
        return "Matrices cannot be added. Check dimensions."

def main():
    matrices = []
    while True:
        print("\nMatrix Calculator Menu:")
        print("1. Input a new matrix")
        print("2. Calculate inverse of a matrix")
        print("3. Calculate determinant of a matrix")
        print("4. Multiply two matrices")
        print("5. Add two matrices")
        print("6. Exit")
        
        choice = input("Enter your choice (1-6): ")
        
        if choice == '1':
            matrices.append(input_matrix())
            print(f"Matrix {len(matrices)} added successfully.")
        elif choice == '2':
            if not matrices:
                print("No matrices available. Please input a matrix first.")
            else:
                index = int(input(f"Enter the matrix number (1-{len(matrices)}): ")) - 1
                result = inverse(matrices[index])
                print("Inverse:")
                print(result)
        elif choice == '3':
            if not matrices:
                print("No matrices available. Please input a matrix first.")
            else:
                index = int(input(f"Enter the matrix number (1-{len(matrices)}): ")) - 1
                result = determinant(matrices[index])
                print(f"Determinant: {result}")
        elif choice == '4':
            if len(matrices) < 2:
                print("At least two matrices are required for multiplication.")
            else:
                index1 = int(input(f"Enter the first matrix number (1-{len(matrices)}): ")) - 1
                index2 = int(input(f"Enter the second matrix number (1-{len(matrices)}): ")) - 1
                result = multiply_matrices(matrices[index1], matrices[index2])
                print("Result of multiplication:")
                print(result)
        elif choice == '5':
            if len(matrices) < 2:
                print("At least two matrices are required for addition.")
            else:
                index1 = int(input(f"Enter the first matrix number (1-{len(matrices)}): ")) - 1
                index2 = int(input(f"Enter the second matrix number (1-{len(matrices)}): ")) - 1
                result = add_matrices(matrices[index1], matrices[index2])
                print("Result of addition:")
                print(result)
        elif choice == '6':
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
