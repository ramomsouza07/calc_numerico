from sympy import symbols, diff, sympify, lambdify

x_sym = symbols('x')

f = input("Digite a função em x (ex: x**3 - 5*x**2 - 4*x + 1): ")
f_sym = sympify(f)
df_sym = diff(f_sym, x_sym)

f = lambdify(x_sym, f_sym, "math")
df = lambdify(x_sym, df_sym, "math")

#intervalo, erro e nmax
a = float(input("Insira o valor próximo para iniciar: "))
erro = float(input("Insira o valor de aproximação, para críterios de parada: "))
nmax = int(input("Insira o número máximo de iterações: "))

#funções
x = [a]
zero_apro = x[0]

if abs(f(x[0])) < erro or nmax <= 0:
    print(f"O valor estimado é de: {x[0]}")
else:
    i = 0
    x_atual = x[i] - (f(x[i]) / df(x[i]))
    x.append(x_atual)

    while (abs(f(x[i + 1]))) < erro or (i < nmax - 1):
        x_atual = x[i] - (f(x[i]) / df(x[i]))
        x.append(x_atual)
        
        if abs(f(x_atual)) < erro:
            break
        i += 1
    print(f"O valor estimado é de: {float(x[i])}")