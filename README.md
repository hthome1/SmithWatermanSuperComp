# SmithWatermanSuperComp
Projeto feito pela disciplina de super computação do 7 semestre da faculdade insper


## Gerando Sequencia de DNAs
Primeiro passa eh rodar o comando
```python3 SequenceGenerator.py```
O codigo gera um arquivo contendo o tamanho de cada sequencia e o dna em si.
Os tamanhos das sequencias de DNA sao de 10 e 20, porem no codigo podem ser alterados para o numero que escolher.

## Compilando o codigo
Rodar o comando 
```g++ -Wall -o3 SmithWaterman.cpp -o sw```

## Rodando o codigo

```./sw < dna.seq```

sw o arquivo gerado pela compilacao e o dna.seq o arquivo gerado pelo codigo em python

## Output
O output sera as duas sequencias de DNA alinhadas e o score maximo.
