def f(x):
    return float(x**3 - 9*x + 3)

# intervalo inicial como float
x = [0.0, 1.0]

# precisão
tol = 0.0005

k = 1
while abs(f(x[-1])) > tol and abs(x[-1] - x[-2]) > tol:
    x_atual = float(x[k] - f(x[k]) * (x[k] - x[k-1]) / (f(x[k]) - f(x[k-1])))
    x.append(x_atual)
    k += 1

x_aprox = float(x[-1])
print(f"A raiz aproximada é: {x_aprox}")
