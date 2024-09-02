# Jogo Interativo em C

## Contexto de Desenvolvimento do Projeto

Este projeto foi desenvolvido como trabalho final para a matéria de Estruturas de Dados 2, com o objetivo de aplicar conceitos de Tipos Abstratos de Dados (TADs), encapsulamento e estruturas de dados complexas, como Grafos, na linguagem de programação C.

A motivação para criar um jogo interativo baseado em texto foi fornecer uma maneira intuitiva e envolvente de compreender a importância das estruturas de dados na resolução de problemas e no desenvolvimento de sistemas. Através da criação de um jogo com interação via terminal, foi possível explorar e demonstrar como diferentes estruturas de dados são utilizadas no gerenciamento de estados e na lógica de jogo.

## Justificativa da Escolha do Estudo de Caso

O estudo de caso escolhido — um jogo digital baseado em texto — foi selecionado pelos seguintes motivos:

- **Didaticidade**: Jogos são uma forma eficaz de aplicar conceitos teóricos. Eles proporcionam uma estrutura natural para implementar estados, transições e interações, facilitando o aprendizado de estruturas de dados.
  
- **Interatividade**: Jogos mantêm o engajamento dos desenvolvedores e usuários, incentivando exploração e experimentação, essenciais para o processo de aprendizagem.

- **Complexidade Gerenciável**: Jogos baseados em texto evitam a complexidade de interfaces gráficas, permitindo foco na lógica de programação e nas estruturas de dados.

- **Versatilidade**: Permite a utilização de várias estruturas de dados para gerenciar locais, NPCs, itens e conexões, oferecendo oportunidades práticas de aprendizado.

## Justificativa da Estrutura de Dados Empregada: Grafos

Os grafos foram escolhidos como estrutura de dados principal para representar o mundo do jogo por diversos motivos:

- **Modelagem Natural do Mundo do Jogo**: são ideais para representar o mundo do jogo, onde locais (vértices) estão conectados por caminhos (arestas).

- **Flexibilidade e Expansibilidade**: permitem fácil expansão do jogo com novos locais e conexões, sem reestruturar o código existente.

- **Eficiência de Navegação**: facilitam a navegação entre locais e a busca por caminhos, aplicando conceitos de algoritmos de grafos.

- **Aplicabilidade em Problemas Reais**: são amplamente utilizados em redes, mapas e sistemas interconectados.

## Instruções para Compilação e Execução

Para compilar e executar o jogo, utilize o script `run.sh` incluído no repositório. Este script automatiza o processo de compilação e execução do jogo.

### Arquivo `run.sh`

Este script compila todos os arquivos fonte e executa o jogo.

```bash
#!/bin/bash

# Compila o jogo
gcc -o jogo main.c game/game.c item/item.c npc/npc.c location/location.c graph/graph.c -Iitem -Inpc -Ilocation -Igraph

# Executa o jogo
./jogo
