# 🥕 Carrot Engine 🥕

## :book: Descrição

*Carrot* é um motor de jogos 2D de código aberto gravado em C++.

🥗 *Carrot* faz parte do ecossistema *Salad* 🥗

## :dart: Objetivo:

Criar um motor de jogos básico baseado no modelo [ECS](https://pt.wikipedia.org/wiki/Entity-component-system). O motor só vai cuidar da parte lógica e de gerenciamento de entidades e componentes.

## :gear: Responsabilidades do motor:

- 🟥 Lógica de atualização
- 🟥 Serialização
- 🟥 Ferramentas auxiliares (grafos e outras estruturas de dados)

Legenda - 🟢: Feito 🔶: Em andamento 🟥: Não iniciado


## <a name="dependencias"></a> :books: Dependências

- ### GCC (g++):
    
    Compilador de C++ da GNU, versão compatível com o padrão C++17. Baixe do site oficial: https://gcc.gnu.org/;

- ### make:
    
    Ferramenta para controlar a criação e limpeza dos arquivos executáveis usados neste projeto. Para Windows, o MinGW já possui o make e geralmente distribuições Linux já vem com a ferramenta instalada. Caso não possua a ferramenta, baixe do site oficial: https://www.gnu.org/software/make/;


## :computer: Executando o projeto:

### A partir do código fonte:

- Garanta que todas as [dependências](#dependencias) estão satisfeitas.
- Execute `make all` para compilar, conectar e criar o executável. Caso tenha alterado algum arquivo após uma primeira execução, o `make all` vai atualizar somente os códigos fonte modificados.
- Execute `./out` para rodar o projeto.
- Execute `make clean` para remover os binários gerados caso queira realizar uma outra compilação.


## :busts_in_silhouette: Contribuindo com o projeto

### Caso não seja um colaborador do projeto:

- Crie uma nova [**issue**](https://github.com/Gaizgrol/Carrot/issues) no projeto.
- Realize um *fork* do projeto no GitHub.
- Faça as alterações necessárias e envie para o seu fork com o padrão de commits utilizado no https://gitmoji.dev.
- Crie uma pull request para a branch main e descreva as alterações realizadas.
- Referencie sua issue na pull request criada.

## :x: Problemas

- Caso não consiga executar algum comando ou não consiga abrir a janela do projeto, verifique se as dependências foram corretamente instaladas.
- Caso tenha algum erro de execução, sinta-se à vontade para criar uma nova [**issue**](https://github.com/Gaizgrol/Carrot/issues) no projeto.

## 🥗 Ecossistema *Salad*:
- 🥬 *Cabbage*: https://github.com/Gaizgrol/Cabbage
- 🥕 *Carrot*: https://github.com/Gaizgrol/Carrot
- 🥦 *Cauliflower*: `// Em breve...`
- 🥒 *Cucumber*: `// Em breve...`
- 🌶️ *Chili*: `// Em breve...`
- 🌽 *Corn*: `// Em breve...`
