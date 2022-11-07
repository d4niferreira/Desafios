def getCycle( num ):
    cont = 1
    while num != 1 :
        if num % 2 == 0 :
            num = num /2
        else :
            num = num *3 + 1
        cont = cont +1
    
    return cont



def main():
    while True:
        try:
            linha = input().split(" ")    
            maior = 0
            i = int(linha[0])
            j = int(linha[1])
            for k in range(i, j+1):
                r = getCycle(k)
                if r > maior:
                    maior = r

            print(f'{i} {j} {maior}')    
        except EOFError as e:
            break


main()



