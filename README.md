# Dicionário com tamanho limitado e inserção/remoção ordenados em C++

Este projeto implementa um dicionário simples em C++. O dicionário armazena pares de chave-valor, onde as chaves são caracteres e os valores são números de ponto flutuante.

## Estrutura do Dicionário

A estrutura `Dicionario` contém dois arrays: `c` para as chaves e `v` para os valores. Os índices `i` e `n` representam o início e o fim do dicionário, respectivamente.

## Funções

O código inclui as seguintes funções:

- `inicializar`: Inicializa o dicionário.
- `vazio`: Verifica se o dicionário está vazio.
- `cheio`: Verifica se o dicionário está cheio.
- `consultar`: Consulta uma chave no dicionário.
- `inserir`: Insere uma chave e um valor no dicionário.
- `remover`: Remove uma chave e seu valor associado do dicionário.
- `imprimir`: Imprime todas as chaves e valores do dicionário.

## Testes

O programa principal (`main`) realiza uma série de testes nas funções do dicionário, incluindo a inserção de chaves e valores, a consulta de chaves, a remoção de chaves e a impressão do dicionário.

## Como compilar e executar

Para compilar o código, você pode usar o compilador g++:

```bash
g++ main.cpp -o main
