# Projeto: Conversão de Árvores 2-3-4 em Árvores Rubro-Negras

## 🏫 Universidade Federal de Itajubá (UNIFEI)  
**Disciplina:** Algoritmos e Estruturas de Dados II (CTCO-02)  
**Professora:** Vanessa Souza  
**Assunto:** Árvores Balanceadas  
**Trabalho Prático 2**  
**Entrega:** 02/07/2025  

---

## 👥 Integrantes do Grupo

- Nome 1: Rodrigo Ruan Souza Viana
- Nome 2: Caio Mendes Coutinho e Garcia
- Nome 3: Diego Silva Cortez

---

## 📋 Descrição do Projeto

Este projeto tem como objetivo principal a **implementação da conversão de uma árvore 2-3-4 em uma árvore Rubro-Negra** na linguagem C.  

As árvores 2-3-4 e Rubro-Negras são estruturas de dados balanceadas com propriedades equivalentes, sendo possível transformar uma estrutura na outra.

---

## 📌 Funcionalidades

- Leitura de arquivo com os valores para a construção da árvore 2-3-4.
- Inserção e remoção de elementos na árvore 2-3-4.
- Impressão da árvore 2-3-4.
- Conversão da árvore 2-3-4 em uma árvore Rubro-Negra.
- Inserção e remoção de elementos na árvore Rubro-Negra.
- Impressão da árvore Rubro-Negra.
- Registro de métricas como número de *splits*, altura da árvore, blocos ocupados, rotações, e *merges*.
- Interface textual com menus interativos.

---

## 📂 Estrutura do Projeto

```bash
├── algoritmos/
│   ├── Arvore234.c/.h         # Implementação da árvore 2-3-4
│   ├── RubroNegra.c/.h        # Implementação da árvore Rubro-Negra
│   ├── conversor.c/.h         # Conversão entre 2-3-4 e Rubro-Negra
│   └── utils.c/.h             # Utilitários e funções auxiliares
├── dados/
│   ├── entrada_100.txt        # Arquivo de teste com 100 elementos
│   └── ...
├── testes/
│   ├── benchmarking.c         # Scripts para análise de desempenho
│   └── resultados.csv         # Tabela com resultados estatísticos
├── relatorio/
│   ├── relatorio.pdf          # Relatório final do trabalho
│   └── relatorio.tex          # Arquivo em LaTeX (modelo do curso)
└── README.md                  # Este arquivo
