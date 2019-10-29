select nome from clientes;

select nome, valor from produtos;

select clientes.nome, telefones.numero from clientes, telefones where clientes.codcliente=telefones.codcliente;
select clientes.nome, telefones.numero from clientes inner join telefones on clientes.codcliente=telefones.codcliente;

select clientes.nome, produtoencomendas. encomendas.horaentrega from clientes, encomendas where clientes.codcliente=encomendas.codcliente;

-- quais produtos foram comprados com e sem encomendas feitas
select produtos.nome, produtoencomendas.quantidade, produtovendas.quantidade
  from produtos inner join produtoencomendas 
    on produtos.codproduto=produtoencomendas.codproduto
    inner join produtovendas 
    on produto.codproduto=produtovendas.codproduto;
