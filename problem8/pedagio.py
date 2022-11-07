''' 
Daniele Ferreira da Silva  2019.1.08.033
José Flávio Lopes		   2019.1.08.045
'''

def main():
    casos = int(input())
    input()

    for i in range(casos):
        fotos = []
        tabelamento = {}
        horas = input().split(" ")
        while True:
            try:
                foto = input().split(" ")
                if (len(foto) == 1):
                    break
                tabelamento[foto[0]] = 0
                fotos.append(foto)
            except EOFError as e:
                break

        # ordenar 1º por placa, 2º por data/horario
        fotosOrdenadas = sorted(fotos, key=lambda x: (x[0], x[1]))
        
        # cobrar
        i = 0
        while i < len(fotosOrdenadas) -1:
            if  fotosOrdenadas[i][0] == fotosOrdenadas[i+1][0]  and fotosOrdenadas[i][2] == 'enter' and fotosOrdenadas[i+1][2] == 'exit':
                km = abs(int(fotosOrdenadas[i + 1][3]) - int(fotosOrdenadas[i][3]))
                horario = int(fotosOrdenadas[i][1][6] + fotosOrdenadas[i][1][7])
                preco = (km * int(horas[horario])) / 100 + 1
                tabelamento[fotosOrdenadas[i][0]] += preco 
                i += 2
            else: 
                i += 1
        
        chaves = sorted(tabelamento)

        #imprimir
        for key in chaves:
            if tabelamento[key] != 0:
                print(f'{key} ${tabelamento[key]+2:.2f}')
        print(" ")

main()
