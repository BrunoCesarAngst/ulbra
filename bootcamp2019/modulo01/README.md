# Ambiente e conceitos

## Criando uma aplicação.

Criação da pasta `mkdir modulo01`.

Logo em seguida o comando `yarn init -y`, ele cria o packge.json com toda a configuração da aplicação para um possível pacote de distribuição, além de conter todas as dependências usadas na mesma. Esse arquivo é importante, pois, se alguem pegar esse projeto, ela só precisará digitar o comando `yarn`, instalando todas as dependências do projeto.

Na sequência o comando `yarn add express`, esse automaticamente criará uma pasta **node_modules**, que contém todas as dependências do projeto, que por sua vez, também tem dependências no pacote *express*

Para não subir essa pasta, para o GitHub, com tamanha informação, criasse um arquivo `touch .gitignore` para mostra ao git o que ele deve iginorar *diretórios ou arquivos* na momento de dar um *git push* para o repositório remoto, gravando nesse arquivo o nome da pasta `echo 'node_modules' >> .gitignore`.

Então para começar o codigo da aplicação crio o arquivo *index.js* que o ponto de entrada da aplicação, daqui em diante comento dentro do próprio arquivo.
