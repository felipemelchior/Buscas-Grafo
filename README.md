# Buscas BFS e DFS de grafos

Este código é uma revisão da estrutura de dados grafo, com lista de adjacencia.

## Uso
Dependências: <br>
```
$ g++ e openMP (usado para calcular o tempo das funções)
```
<br>

```
Um arquivo de texto com a estrutura de arestas, exemplo: 1  3
```

<br>

Para compilar use: <br>
```
$ ./run.sh
```
<br>
Após compilar, o programa irá rodar com um arquivo de grafo padrão (Orkut) e localizará o nodo 1. <br>
Após finalizado, pode-se usar:
<br>
<br>

```
$ ./grafo <Arquivo_de_grafo> <Nodo_para_localizar>
```

## Resolvendo erros
Se ao tentar rodar o arquivo <b>run.sh</b> você receber este erro: 
<br>

```
$ bash: ./run.sh: Permission denied
```

<br>
Basta realizar este comando: 
<br>

```
$ chmod +x run.sh
```

<br>

## Desenvolvedor

* Felipe Homrich Melchior - UNIPAMPA - [Perfil GitHub](https://github.com/homdreen)
