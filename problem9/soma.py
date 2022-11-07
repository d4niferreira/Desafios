''' 
Daniele Ferreira da Silva 2019.1.08.033
José Flávio Lopes         2019.1.08.045
'''

def main():
    casos = int(input())
    while casos > 0:
        cont = 0
        numero = input()
        palindromo = False
        aux = 0
        while  not palindromo:
            numReverso = numero[::-1]
            if numReverso == numero:
                palindromo = True
            else:
                aux = int(numero) + int(numReverso)
                numero = str(aux)
                cont += 1             
        print(f'{cont} {numero}')
        casos -=1

main()