# Problema dos filósofos famintos

Consiste em cinco filósofos que passam suas vidas meditando e comendo. Uma mesa
redonda é compartilhada entre os filósofos contendo cinco cadeiras.

Cada Filósofo tem um prato de espaguete. Para que o filósofo consiga comer ele precisa de 2 garfos. A vida de cada filósofo consiste em períodos nos quais ele alternadamente come e pensa.

Quando ele medita ele não interage com seus colegas. Quando um filósofo sente fome ele tenta pegar os dois garfos mais próximos de si (direita e esquerda do seu próprio prato). Um filósofo pode pegar apenas um garfo de cada vez (a ordem não importa) e, é claro, não poderá pegar nenhum garfo que esteja na mão de outro filósofo.

## Restrições

As restrições conhecidas deste problema são as seguintes:

  - Cada filósofo deve funcionar de forma independente e paralela (threading);
  - Nenhum filósofo deve ficar sem comer por um tempo prolongado (starvation);
  - Um garfo não pode ficar trancado com um filósofo (deadlock).

## Resolução

Para resolver o problema resolvemos separá-lo em partes, usando classes do C++.
Existem 4 classes na solução:

  - ProblemaFilosofos
  - Garfo
  - Filósofo
  - Messenger

A classe ProblemaFilosofos é responsável por coordenar a criação e destruição dos
filósofos bem como dos garfos. Já a classe Messenger apenas possibilita a comunicação do estado atual de cada filósofo e outras mensagens de log para a saída padrão.

As classes mais importantes são Filósofo e Garfo respectivamente, a primeira contém
a criação de cada thread/Filósofo e a segunda contém o estado dos Garfos.

O ciclo da função `vive()` define muito bem como a coisa acontece, enquanto o Filósofo estiver vivo ele vai seguir o seguinte ciclo de vida:

  - **Pensar**, nesta tarefa ele apenas espera, sem usar recursos de área crítica;
  - **Pegar garfos**, quando estiver com fome ele vai tentar pegar um Garfo e depois o outro. O Garfo é um recurso compartilhado entre dois Filósofos, ou seja de área crítica;
  - **Comer**, se ele possui os dois Garfos necessários ele pode comer;
  - **Soltar garfos**, depois de comer ele deve soltar os Garfos para liberar a chance para os outros;

Atenção para um item imporante: caso o filósofo consiga somente um garfo ele deve soltar este garfo e esperar (pensar) mais um pouco.

## Observações

Não usamos tempo randômico na solução pelo fato das threads não serem fisicamente iniciadas ao mesmo tempo, pois elas estão sendo iniciadas por um loop na thread principal.

Ao invés disso fixamos um tempo de espera para o filósofo pensado e um para o filósofo comendo.

Outros pontos importantes se encontram nos comentários do código.

## Download do binário pronto

Disponibilizamos o programa pré-compilado para Windows e OSX x86_64.

OBS: Usuários de Windows devem ter [Visual C++ 2013](http://www.microsoft.com/en-us/download/details.aspx?id=40784)+ instalado pois o sistema não possui as bibliotecas padrão da linguagem nativamente. Geralmente máquinas que já rodam outras aplicações como jogos ou browsers e etc já têm este componente instalado.

O binário está disponível nos item Releases do repositório GitHub.

Link direto para Windows: [ProblemaFilosofos.exe](https://github.com/mkautzmann/problema-paralelismo/releases/download/1.0.0w/ProblemaFilosofos.exe.zip)

Link direto para OSX: [ProblemaFilosofos](https://github.com/mkautzmann/problema-paralelismo/releases/download/1.0.0/ProblemaFilosofos)

## Fazendo build do projeto

Caso você deseja compilar na sua máquina siga os passos a seguir:

O programa dos filósofos usa CMake para facilitar o build muiltiplatafoma.

  - Se você ainda não possui o CMake, [instale ele](http://www.cmake.org/download/).
  - Tenha certeza que você possui um compilador C++ que suporte C++11, o CMake vai verificar e informar você.
  - Se OK até aqui vá até a pasta `build/src` do projeto e rode `cmake .`
  - Em sistemas Unix/Linux isso vai criar um Makefile para você rodar `make`. O binário vai estar na pasta `build/src/bin`
  - Em Windows você precisa do [Visual Studio 2013](http://www.microsoft.com/en-us/download/details.aspx?id=44914)+ ou superior, depois de rodar o comando o CMake vai gerar um `.sln` que quando compilado vai gerar um binário para você.
