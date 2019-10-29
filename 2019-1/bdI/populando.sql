--departamentos, funcionarios, clientes, pessoa_juridica e pessoa_fisica

insert into departamentos values (default, 'compras', '2500.00'); 
insert into departamentos values (default, 'finaceiro', 3000);
insert into departamentos values (default, 'vendas', 2000);

insert into funcionarios values (default, 3, 'Rafael', 51999999999);
insert into funcionarios values (default, 2, 'Leonardo', 51979797979);
insert into funcionarios values (default, 1, 'Ramon', 51912345678);

update departamentos set salario = 2500 where id = 1;
update funcionarios set telefone = 45998765432 where id = 3;
update clientes set endereco = 'Rua dos bons programadores' where id = 5;
update fornecedores set cnpj_empresa = 'kd o cnpj' where cnpj_empresa = '00000000000000';
update fornecedores set nome = 'Bruno', marca = 'Apple', email = 'mbcangst@gmail.com', produtos = 'Mais Mais' where id = 6;

delete from fornecedores where produtos = 'cpu';
