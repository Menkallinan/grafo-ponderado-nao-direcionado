# Grafo com Lista de Adjacências

Este projeto implementa um grafo utilizando listas de adjacências em C. O grafo é não direcionado e ponderado, permitindo operações como inserção e remoção de arestas, busca em profundidade (DFS), busca em largura (BFS), exibição de vizinhos, cálculo da popularidade de vértices e geração de uma matriz de adjacências.

## Problema Resolvido

O código foi desenvolvido para manipular grafos de forma eficiente, permitindo:

- **Inserção e remoção de arestas**: Adiciona ou remove conexões entre vértices com pesos específicos.
- **Busca em profundidade (DFS)**: Percorre o grafo explorando cada ramificação até o fim antes de retroceder.
- **Busca em largura (BFS)**: Percorre o grafo nível por nível, a partir de um vértice inicial.
- **Exibição de vizinhos**: Lista todos os vértices conectados a um determinado vértice.
- **Cálculo da popularidade**: Identifica o vértice com o maior número de vizinhos.
- **Matriz de adjacências**: Gera uma representação matricial do grafo.

## Como Funciona

O grafo é representado por um vetor de listas encadeadas, onde cada posição do vetor corresponde a um vértice, e cada lista contém os vértices adjacentes e os pesos das arestas. O código oferece uma interface interativa para executar as operações mencionadas.

## Exemplos de Uso

### 1. Criando um grafo com 4 vértices
```bash
4
```

### 2. Adicionando arestas
```bash
+ 1 2 10  # Adiciona uma aresta entre os vértices 1 e 2 com peso 10
+ 1 3 20  # Adiciona uma aresta entre os vértices 1 e 3 com peso 20
+ 2 4 30  # Adiciona uma aresta entre os vértices 2 e 4 com peso 30
```

### 3. Verificando o peso de uma aresta
```bash
w 1 2     # Exibe o peso da aresta entre os vértices 1 e 2
```
**Saída:**
```bash
10
```

### 4. Exibindo os vizinhos de um vértice
```bash
vizinhos 1  # Exibe os vizinhos do vértice 1
```
**Saída:**
```bash
2 3
```

### 5. Gerando a matriz de adjacências
```bash
matriz
```
**Saída:**
```bash
- 10 20 -
10 - - 30
20 - - -
- 30 - -
```

### 6. Executando uma busca em profundidade (DFS)
```bash
dfs
```
**Saída:**
```bash
[1 2 4 3], peso total 60
1 componente(s)
```

### 7. Executando uma busca em largura (BFS)
```bash
bfs 1 4  # Busca o caminho mais curto entre os vértices 1 e 4
```
**Saída:**
```bash
1 2 4
2 aresta(s), peso total 40
```

### 8. Removendo uma aresta
```bash
- 1 2     # Remove a aresta entre os vértices 1 e 2
```

### 9. Finalizando o programa
```bash
F         # Encerra o programa
```

## Estrutura do Código

- **Lista de Adjacências**: Cada vértice é representado por uma lista encadeada de nós, onde cada nó contém o valor do vértice adjacente e o peso da aresta.
- **Fila**: Utilizada para implementar a BFS.
- **DFS e BFS**: Implementados de forma recursiva (DFS) e iterativa (BFS).
- **Matriz de Adjacências**: Gerada a partir da lista de adjacências.

## Como Compilar e Executar

### 1. Compile o código:
```bash
gcc -o main main.c
```

### 2. Execute o programa:
```bash
./main
```
Siga as instruções interativas para manipular o grafo.

## Limitações

- O código não verifica a existência de arestas duplicadas.
- A fila utilizada na BFS tem um tamanho máximo fixo (`MAX = 100`).
- Não há suporte para grafos direcionados.

## Melhorias Futuras

- Adicionar suporte para grafos direcionados.
- Implementar verificações de arestas duplicadas.
- Permitir a leitura de grafos a partir de arquivos.
- Adicionar funcionalidades como cálculo do caminho mínimo (Dijkstra) e árvore geradora mínima (Kruskal/Prim).

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Licença

Este projeto está licenciado sob a **MIT License**.

