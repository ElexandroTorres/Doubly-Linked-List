
List
====
**Projeto de implementação do TAD List**

Autoria de **Elexandro Torres Tavares**


Implementação da classe list utilizando uma lista encadeada com nó cabeça e nó calda.

Compilação:
-------------
Para compilar, devemos acessar o diretório do projeto e em seguida entrar na pasta **build**. iremos executar o cmake com o CMakeLists.txt disponível no projeto.
Exemplo:
```
~/Documentos/Doubly-Linked-List/build$ cmake -G "Unix Makefiles" ..
```
Em seguida usamos o comando **make** para gerar o executável.
```
~/Documentos/Doubly-Linked-List/build$ make
```
O Makefile está configurado para compilar um arquivo principal **main** a qual deve esta as chamadas para a execução da classe list. Sendo assim, dentro da pasta /src deverá haver um arquivo de testes(ou com outra finalidade para utilizar o list) com o nome **main.cpp**. 

Executando os testes:
-------------
Para executar os testes, ou qualquer outra utilização da classe list, basta executar o comando ./list.
```
~/Documentos/Doubly-Linked-Listr/build$ ./list
```



