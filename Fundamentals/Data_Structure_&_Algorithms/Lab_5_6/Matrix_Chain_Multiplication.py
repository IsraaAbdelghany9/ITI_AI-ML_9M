# Matrix_Chain_Multiplication 

def Matrix_Chain_Multiplication(p):
    n = len(p) - 1 
    m = [[0 for i in range(n)] for j in range(n)] 
    s = [[0 for i in range(n)] for j in range(n)] 

    for l in range(2, n+1): # l is the chain length combining each chain length from 2 , 3, 4, ... n

        for i in range(n-l+1): # i is the start index
            j = i + l - 1 # j is the end index
            m[i][j] = float('inf') # initialize with infinity not with 0 as we are going to take minimum of the values


            for k in range(i, j): # k is the split index
                q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1] # calculate the number of multiplications

                if q < m[i][j]: # if the number of multiplications is less than the previous value
                    m[i][j] = q
                    s[i][j] = k
    return m, s


def print_optimal_parens(s, i, j):
    if i == j:
        print(f"A{i}", end="")
    
    elif i == j - 1:
        print(f"(A{i} * A{j})", end="")

    else:
        print("(", end="")
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j]+1, j)
        print(")", end="")


p = [30, 35, 15, 5, 10, 20, 25]
m, s = Matrix_Chain_Multiplication(p)
print("Optimal Parenthesization:")
print_optimal_parens(s, 0, len(p)-2)
print("\nMinimum number of multiplications:", m[0][len(p)-2])

