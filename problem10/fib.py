''' 
Daniele Ferreira da Silva 2019.1.08.033
José Flávio Lopes         2019.1.08.045
'''

def fib(a, b):
    f1 = 1
    f2 = 1
    fn = f1 + f2
    if a == 1:
        cont = 1
    else: 
        cont = 0
    while fn <= b:
        if fn >= a:
            cont += 1 
        f1 = f2
        f2 = fn
        fn = f1 + f2 
    
    return cont

def main():
    
    while True:
        linha = input().split(" ")
        a = int(linha[0])
        b = int(linha[1])

        if a == 0 and b == 0:
            break

        print(fib(a,b))



main()