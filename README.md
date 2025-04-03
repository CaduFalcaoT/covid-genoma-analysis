# Análise de Sequências Genômicas do SARS-CoV-2

Este projeto implementa uma tabela de espalhamento (hash table) para contar a frequência de blocos de 6 bases nitrogenadas (6-mers) no genoma do Coronavírus (SARS-CoV-2). O código foi desenvolvido em C++ e segue os requisitos da questão adaptada pelo professor Rodrigo Nonamor (UFRPE).

## Funcionalidades
- ✅ **Leitura do genoma**: Processa um arquivo `.txt` com sequências de DNA.
- ✅ **Divisão em blocos de 6 bases**: Cada linha é dividida em blocos consecutivos de 6 caracteres (sem sobreposição).
- ✅ **Contagem com tabela hash**: Usa encadeamento externo para tratar colisões.
- ✅ **Saída em arquivo**: Gera um arquivo com os blocos e suas frequências.

## Como Executar

### **Pré-requisitos**
- Compilador C++ (ex: `g++`).
- CLion instalado e configurado.
- Arquivo de entrada no formato `.txt` (ex: `data/genoma.txt`).

### **Compilação e Execução no CLion**
1. **Abra o projeto no CLion**
2. **Compile o código:**
   - Clique no botão de compilação no CLion ou use o atalho `Shift + F9`.
3. **Execute o programa:**
   - No CLion, defina os argumentos de linha de comando:
      - Vá em `Edit Configurations` > `Program Arguments` e adicione:
        ```
        data/genoma.txt data/output.txt
        ```
   - Clique no botão de execução ou use `Shift + F10`.

4. **Verifique a saída:**
   ```bash
   cat data/output.txt
   ```

## Estrutura do Projeto
```
.
├── data/
│   ├── genoma.txt          # Arquivo de entrada (genoma do SARS-CoV-2)
│   └── output.txt          # Arquivo de saída (blocos e contagens)
├── src/
│   ├── main.cpp            # Código-fonte principal
└── README.md               # Este arquivo
```

## Exemplo de Saída
O arquivo `output.txt` terá o formato:
```
ATTAAA 3
AAGGTT 1
GGTTTA 1
TTTATA 1
...
```
(Cada bloco é listado com sua frequência no genoma.)

## Referências
- [NCBI: Genoma do SARS-CoV-2](https://www.ncbi.nlm.nih.gov)
- [Método de Horner para Hashing](https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html)

