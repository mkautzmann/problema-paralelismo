# Problema do barbeiro dorminhoco

Existe uma barbearia com uma cadeira comum neste tipo de estabelecimento,
também existe uma série de lugares para que os clientes possam esperar. Caso não
tenha clientes, o barbeiro senta em sua cadeira e dorme. Quando chegarem
fregueses, enquanto o barbeiro estiver cortando o cabelo de outro, estes devem ou
sentar, se houver cadeira vazia, ou ir embora, se não houver nenhuma cadeira livre.

## Restrições

 - O barbeiro só pode atender um cliente por vez;
 - O barbeiro dorme quando não existam clientes querendo atenção;
 - O sistema deve executar concorrentemente as funções de barbeiro e clientes;
 - Existem 5 cadeiras de espera no estabelecimento, se chegar algum cliente extra ele deve ir embora.

## Solução

Para resolver utilizamos a técnica de exclusão mútua através da biblioteca `<mutex>` do C++.

Basicamente temos o barbeiro rodando em uma thread e criamos uma thread para cada cliente.

Os clientes concorrem pela atenção do barbeiro, que vai recebendo um cliente por vez conforme possível.

O intervalo de chegada de cada cliente é randômico assim como o tempo que o barbeiro leva em cada corte.

Mais detalhes estão disponíveis em comentários no fonte.

## Download do binário pronto

Disponibilizamos o programa pré-compilado para Windows e OSX x86_64.

OBS: Usuários de Windows devem ter [Visual C++ 2013](http://www.microsoft.com/en-us/download/details.aspx?id=40784)+ instalado pois o sistema não possui as bibliotecas padrão da linguagem nativamente. Geralmente máquinas que já rodam outras aplicações como jogos ou browsers e etc já têm este componente instalado.

O binário está disponível nos item Releases do repositório GitHub.

Link direto para Windows: [ProblemaBarbeiro.exe](https://github.com/mkautzmann/problema-paralelismo/releases/download/1.0.0wb/ProblemaBarbeiro.exe.zip)

Link direto para OSX: [ProblemaBarbeiro](https://github.com/mkautzmann/problema-paralelismo/releases/download/1.0.0b/ProblemaBarbeiro)

## Fazendo build do projeto

Caso você deseja compilar na sua máquina siga os passos a seguir:

O programa do barbeiro usa CMake para facilitar o build muiltiplatafoma.

  - Se você ainda não possui o CMake, [instale ele](http://www.cmake.org/download/).
  - Tenha certeza que você possui um compilador C++ que suporte C++11, o CMake vai verificar e informar você.
  - Se OK até aqui vá até a pasta `build/src` do projeto e rode `cmake .`
  - Em sistemas Unix/Linux isso vai criar um Makefile para você rodar `make`. O binário vai estar na pasta `build/src/bin`
  - Em Windows você precisa do [Visual Studio 2013](http://www.microsoft.com/en-us/download/details.aspx?id=44914)+ ou superior, depois de rodar o comando o CMake vai gerar um `.sln` que quando compilado vai gerar um binário para você.
