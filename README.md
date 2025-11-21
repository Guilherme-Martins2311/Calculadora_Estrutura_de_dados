# Calculadora_Estrutura_de_dados 
README — Avaliador de Expressões Numéricas em C
Este projeto implementa um avaliador de expressões matemáticas em notação pós-fixa, capaz de:
•	Converter pós-fixa para infixa
•	Calcular o valor numérico da expressão
•	Suportar:
o	Operadores: + - * / ^
o	Funções: sen cos tg log raiz

Os arquivos principais são:
•	main.c
•	expressao.c
•	expressao.h


Como compilar
Abra o terminal na pasta do projeto e execute:

gcc main.c expressao.c -lm -o programa
ou
gcc main.c expressao.c –o programa


Como executar
./programa


Como usar o programa
Após executar, o programa pedirá uma expressão em notação pós-fixa:
Exemplo:
3 4 + 5 *
Resultado esperado:
Forma Infixa: ((3 + 4) * 5)
Valor: 35

