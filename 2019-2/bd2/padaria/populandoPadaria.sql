-- cadastro de clientes
  insert into clientes (nome, email, cnpj) 
    values ('Gabriele Pereira De Vargas', 'gabriele.vargas@rede.ulbra.br', 11111);
  insert into clientes (nome, email, cnpj) 
    values ('Rafaela Serafim Magnus', 'rafaela.magnus@rede.ulbra.br', 22222);
  insert into clientes (nome, email, cpf) 
    values ('Luciano Evaldt Magnus', 'luciano.magnus@rede.ulbra.br', 33333);
  insert into clientes (nome, email, cpf) 
    values ('Bruno César Angst', 'bruno.angst@rede.ulbra.br', 44444);
  -- cadastro de funcionários
  insert into funcionarios (nome, funcao, dependentes)
    values ('Fulano', 'Padeiro', 'Fulana e Fulaninho');
  insert into funcionarios (nome, funcao)
    values ('Ciclano', 'Balconista');
  insert into funcionarios (nome, funcao, dependentes)
    values ('Beltrana', 'Caixa', 'Beltraninha');

-- cadastro de tipos de endereços
  insert into tipodeenderecos (descricao) values ('Residencial');
  insert into tipodeenderecos (descricao) values ('Condominial');
  insert into tipodeenderecos (descricao) values ('Comercial');

-- cadastro de endereços
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('11111', 'Felicidade', 'Sem Volta', 777, 'Casa', 1);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('22222', 'Alegria', 'Não Saio Daqui', 111, 'Casa 5C', 2);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('33333', 'Bom Começo', 'Estou Indo', 222, 'Empresa X', 3);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('44444', 'Bom Começo', 'Vem Comigo', 333, 'Empresa Y', 3);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('55555', 'Resiliência', 'Rota Certa', 4444, 'Casa', 1);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('55555', 'Confiança', 'Verdadeiro Caminho', 5555, 'Casa', 1);
  insert into enderecos (cep, cidade, rua, numero, complemento, codTipoDeEndereco)
    values ('55555', 'Sucesso', 'Sempre Passo Por Aqui', 1010, 'Casa', 1);

-- cadastro de endereço de funcionarios
  insert into enderecodosfuncionarios (codEndereco, codFuncionario) values (7, 1);

  insert into enderecodosfuncionarios (codEndereco, codFuncionario) values (5, 2);

  insert into enderecodosfuncionarios (codEndereco, codFuncionario) values (6, 3);
  -- a ordem endereço e funcionario pode ser diferente!

-- cadastro de endereço dos clientes
  -- as empresárias
  insert into enderecoclientes (codEndereco, codcliente) values (4, 1);
  insert into enderecoclientes (codEndereco, codcliente) values (3, 2);
  
  insert into enderecoclientes (codEndereco, codcliente) values (2, 3);
  insert into enderecoclientes (codEndereco, codcliente) values (1, 4);

-- cadastro de telefones
   insert into telefones (numero, codFuncionario) values ('741852963', 1);
   insert into telefones (numero, codFuncionario) values ('852963741', 2);
   insert into telefones (numero, codFuncionario) values ('963741852', 3);
   insert into telefones (numero, codcliente) values ('986753421', 1);
   insert into telefones (numero, codcliente) values ('142753869', 2);
   insert into telefones (numero, codcliente) values ('427538691', 3);
   insert into telefones (numero, codcliente) values ('753869142', 4);
-- cadastro de produtos
  insert into produtos (nome, unidade, valor, descricao, validade, fabricante) values ('Pão Francês', 'gramas', 4.5, 'Farinha, água, sal, açucar e fermento', '2019-08-28', 'interno');
  insert into produtos (nome, unidade, valor, descricao, validade, fabricante) values ('Rosca de Polvilho', 'gramas', 10.5, 'Polvilho, água, sal','2019-08-24', 'interno');
  insert into produtos (nome, unidade, valor, descricao, validade, fabricante) values ('Chocolate Quente', 'unidade', 8, 'Leite, Chocolate e açucar', '2019-08-22', 'interno');
  insert into produtos (nome, unidade, valor, descricao, validade, fabricante) values ('Manteiga',  'unidade', 6.3, 'Gordura animal', '2019-11-28', 'externo');
-- cadastro de encomendas
  insert into encomendas (datapedido, dataentrega, horaentrega, codFuncionario, codcliente) values ('2019-07-22', '2019-08-22', '19:47', 2, 4);
  insert into encomendas (datapedido, dataentrega, horaentrega, codFuncionario, codcliente) values ('2019-08-15', '2019-08-22', '10:30', 2, 3);
  insert into encomendas (datapedido, dataentrega, horaentrega, codFuncionario, codcliente) values ('2019-08-22', '2019-08-22', '09:47', 2, 2);
  insert into encomendas (datapedido, dataentrega, horaentrega, codFuncionario, codcliente) values ('2019-07-22', '2019-09-15', '19:47', 2, 1);
-- cadastro de produtos encomendados
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (1, 1, 300);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (2, 1, 130);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (1, 3, 150);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (2, 3, 130);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (3, 3, 2);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (4, 3, 1);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (2, 2, 1500);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (1, 4, 500);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (2, 4, 600);
  insert into produtoencomendas (codproduto, codencomendas, quantidade) values (3, 4, 8);
-- cadastro de vendas
  insert into vendas (codFuncionario, codencomendas) values (3, 1);
  UPDATE vendas set datahora='2019-08-22' where codVenda=1;
  insert into vendas (codFuncionario, codencomendas) values (3, 2);
  UPDATE vendas set datahora='2019-08-22' where codVenda=2;
  insert into vendas (codFuncionario, codencomendas) values (2, 3);
  UPDATE vendas set datahora='2019-08-22' where codVenda=3;
  insert into vendas (codFuncionario, codencomendas) values (2, 4);
  UPDATE vendas set datahora='2019-09-15' where codVenda=4;
  insert into vendas (codFuncionario, datahora) values (3, '2019-09-01');
  insert into vendas (codFuncionario, datahora) values (3, '2019-08-23');
-- cadastro de produtos vendas
  insert into produtoVendas (codProduto, codVenda, quantidade) values (2, 5, 3);
  insert into produtoVendas (codProduto, codVenda, quantidade) values (4, 5, 1);
  insert into produtoVendas (codProduto, codVenda, quantidade) values (1, 6, 437);
  insert into produtoVendas (codProduto, codVenda, quantidade) values (2, 6, 130);
  insert into produtoVendas (codProduto, codVenda, quantidade) values (3, 6, 3);
  insert into produtoVendas (codProduto, codVenda, quantidade) values (4, 6, 2);
-- cadastro

