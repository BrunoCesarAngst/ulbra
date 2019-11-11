# Desafio Cervantes Tecnologia

## Aqui foi desenvolvido um CRUD, aplicado para Desktop Windows

### Foi utilizado Windows Forms no Visual Studio e para o SGBD foi utilizado o PostgreSQL

**O sistema se compõem da seguinte maneira:**

* Mantem um cadastro de clientes com o seu código, nome e idade.

* O banco de dados tem uma tabela com estes campos sendo eles obrigatórios.

* Cada registro, gera um log com as operações ocorridas, gravando a data e hora da operação assim como o tipo de operação (Insert; Update; Delete).

## Instruções de Teste

1. Execute o script para a geração do banco de dados e suas respectivas tabelas.

2. Abra a pasta DesafioCervantes, abra a pasta Forms e de duplo clique em fmCliente.cs que irá abrir o form.

3. Com o form aberto, inicie o form e será aberta a janela da aplicação.

4. Efetue um novo cadastro de cliente clicando primeiramente no botão "Novo", insira os dados e salve no botão "Salvar" e atualize os dados clicando em Listar.

5. Para a edição de valor clique na linha correspondente, altere os valores desejados e salve e atualize os dados clicando em Listar.

6. Para a exclusão de um cliente, clique na linha correspondente, clique em Deletar e atualize os dados clicando em Listar.

> Para fazer a conexão da aplicação com o DB foi usado o provedor de dados .NET de código aberto do PostgreSQL, o Npgsql.

 ![Windows Form](https://github.com/BrunoCesarAngst/ulbra/blob/master/CervantesTecnologia/imagens/form "Windows Form")
