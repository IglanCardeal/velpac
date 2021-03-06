<div align="center">
  <img src="./frontend/public/img/V.png" height="auto" width="160" alt="Velpac" />
  
# VELPAC

<br>

### :vertical_traffic_light: Site de divulgação da pseudo empresa Velpac e seu produto de gerenciamento de semáforos.

</div>

<div align="center">

![version](https://img.shields.io/badge/version-1.0.0-green) ![npm](https://img.shields.io/npm/v/npm) ![node-current](https://img.shields.io/badge/nodejs-%3E%3D12.0.0-green) ![bootstrap](https://img.shields.io/badge/bootstrap-v4.0-blueviolet) ![GitHub](https://img.shields.io/github/license/iglancardeal/velpac)

</div>

---

## Status do projeto

- Concluído :muscle:

- [:computer: **Veja o site online aqui**](https://velpac.herokuapp.com/)

## Tabela de conteúdos

<!--ts-->

- [Sobre](#sobre)
- [Onde está hospedada](#host)
- [Como usar localmente](#como-usar)
  - [Pré Requisitos](#como-usar)
- [Tecnologias](#tecnologias)
- [Performance no PageSpeed](#pagespeed)
- [Autor](#autor)
<!--te-->

<div align="justify">

<p id="sobre"></p>

### Sobre :coffee:

![tela-inicial](./frontend/public/img/inicial.png)

Este site realiza a divulgação do projeto desenvolvido para gerenciar semáforos. Este projeto fez parte da avaliação de disciplina _Circuitos Elétricos_, onde foi usado uma aplicação feita usando NodeJS e Arduino para controlar, através de uma interface web, o tempo de um semáforo de uma avenida e uma faixa de pedestre.
Neste site, foi demonstrado o propósito do projeto:

- o problema;
- a solução demonstrada;
- como funciona;
- o esquemático do projeto no arduino;
- a arquitetura de comunicação da **interface/servidor/arduino**;
- os serviços oferecidos;
- a documentação;
- a equipe envolvida no projeto;
- contato da empresa(pseudo contato) e da equipe(contato real dos integrantes);

<p id="host"></p>

### Onde está? :rocket:

Este site está hospedado na plataforma [Heroku](https://dashboard.heroku.com) de forma gratuita. A plataforma usa a branch `master` deste projeto para realizar o deploy da aplicação, ou seja, qualquer alteração nesta branch irá refletir na aplicação em produção.

<p id="como-usar"></p>

### Como usar localmente? :pushpin:

Para usar localmente em sua máquina, voce deve ter instalado em sua máquina o [NodeJS](https://nodejs.org/en/) com uma versão minima recomendada `v12.0.0` e o [Git](https://git-scm.com).
Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/).
Para começar, faça o clone deste repositório. Digite o comando no terminal:

```bash
$ git clone https://github.com/IglanCardeal/velpac
```

Acesse a pasta do projeto:

```bash
$ cd velpac
```

Instale as dependências do projeto usando o `npm` ou `yarn` se preferir:

```bash
$ npm install
# ou
$ yarn install
```

Feito isso, execute o comando abaixo e o aplicativo será iniciado localmente como ambiente de desenvolvimento em sua máquina:

```bash
$ npm run dev
# ou
$ yarn dev
```

Agora abra seu navegador na URL `http://localhost:3000` e verá a página inicial do projeto.

<p id="tecnologias"></p>

### Quais tecnologias foram usadas? :wrench:

- [NodeJS](https://nodejs.org/en/)
- [Express](https://expressjs.com/pt-br/) (Framework web)
- [Ejs](https://ejs.co/) (Template engine)
- [Lazyload](https://www.npmjs.com/package/lazyload) (Otimizar carregamento de imagens)
- [Bootstrap](https://getbootstrap.com/) (Framework CSS)
- [Git](https://git-scm.com)
- [VSCode](https://code.visualstudio.com/)

<p id="pagespeed"></p>

### Performance da aplicação no [PageSpeed](https://developers.google.com/speed/pagespeed/insights/?hl=pt-br)

Este site foi otimizado por mim para ter a melhor experiência possível de carregamento da página. Implementei lazyload para imagens e para o iframe do youtube. Compactei as imagens. Removi CSS e fonte não utilizado. Coloquei CSS inline, ou seja, não precisa baixar um arquivo CSS. Todos esses procedimentos resultaram em uma ótima pontuação no PageSpeed. Veja abaixo os resultados para cada plataforma.

- Mobile

  ![mobile performance](./frontend/public/img/ps-mobile.png)

- Desktop

  ![desktop performance](./frontend/public/img/ps-desktop.png)

<p id="autor"></p>

### Autor

 <img style="border-radius: 50%;" src="https://avatars1.githubusercontent.com/u/37749943?s=460&u=70f3bf022f3a0f28c332b1aa984510910818ef02&v=4" width="100px;" alt="iglan cardeal"/>

<b>Iglan Cardeal</b>

Desenvolvido e mantido por Iglan Cardeal :hammer:

Desenvolvedor NodeJS 💻

Entre em contato! 👋🏽

- cmtcardeal@outlook.com :email:
- Instagram [@cmtecardeal](https://www.instagram.com/cmtecardeal/)
- StackOverflow [Cmte Cardeal](https://pt.stackoverflow.com/users/95771/cmte-cardeal?tab=profile)

</div>