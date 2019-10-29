-- bakery database
  create database bakery;

-- tables  
  create table ingredients(
    code_ingredient serial primary key,
    name_ingredient varchar(20) not null
  );

  create table lot(
    code_lot serial primary key,
    shift_lot varchar(20) not null
  );

  create table categories(
    code_category serial primary key,
    category_product varchar(20) not null
  );

  create table products(
    code_product serial primary key,
    name_product varchar(20) not null,
    date_product date not null,
    code_category_pk int not null references categories(code_category),
    code_lot_fk int not null references lot(code_lot),
    amount_products float not null,
    unity_product varchar(20) not null
  );
  alter table products add column expiry_produt date not null;

  create table products_ingredients(
    code_product_fk int not null references products(code_product),
    code_ingredient_fk int not null references ingredients(code_ingredient),
    amount_ingredient float not null,
    unity_ingredient varchar(20) not null
  );

-- insert data
    insert into ingredients(name_ingredient) 
      values
      ('fermento'), ('farinha'), ('água'), ('ovo'), ('sal'), ('açucar'), ('gordura'), ('polvinho azedo'), ('cacau em pó'), ('queijo'), ('tomate'), ('cebola'), ('oregano'), ('calabresa'), ('presunto'), ('alho'), ('granulado')
    ;

    insert into lot(shift_lot) 
      values
      ('manhã'), ('tarde'), ('noite')
    ;

    insert
      into categories(category_product)
      values
      ('pães'), ('bolos'), ('lanches'), ('massas')
    ;
    
    insert
      into products(name_product, date_product, expiry_produt, code_category_pk, code_lot_fk, amount_products, unity_product)
        values
          ('Pão Francês', '2019-10-15', '2019-10-17', 1, 1, 500, 'unidades'),
          ('Rosca', '2019-10-14', '2019-10-15', 1, 1, 30, 'unidades'),
          ('Pão de ló', '2019-10-13', '2019-10-15', 2, 2, 3, 'quilos'),
          ('Bolo de chocolate', '2019-10-13', '2019-10-15', 2, 2, 3, 'quilos'),
          ('Pizza de calabresa', '2019-10-14', '2019-10-15', 3, 3, 10, 'unidades'),
          ('Pão de frios', '2019-10-14', '2019-10-15', 3, 3, 10, 'unidades')
    ;

    insert
      into products_ingredients(code_product_fk, code_ingredient_fk, amount_ingredient, unity_ingredient)
        values
          (1, 1, 45, 'gramas'), (1, 2, 25, 'quilos'), (1, 3, 5, 'litros'), (1, 5, 60, 'gramas'), (1, 6, 180, 'gramas'),
          (2, 3, 0.3, 'litros'), (2, 4, 4, 'unidades'), (2, 5, 20, 'gramas'), (2, 6, 15, 'gramas'), (2, 7, 60, 'gramas'), (2, 8, 1, 'quilo'),
          (3, 1, 15, 'gramas'), (3, 2, 750, 'gramas'), (3, 3, 0.360, 'litros'), (3, 4, 6, 'unidades'), (3, 5, 8, 'gramas'), (3, 6, 240, 'gramas'), (3, 7, 90, 'gramas'),
          (4, 1, 15, 'gramas'), (4, 2, 750, 'gramas'), (4, 3, 0.360, 'litros'), (4, 4, 6, 'unidades'), (4, 5, 8, 'gramas'), (4, 6, 240, 'gramas'), (4, 7, 90, 'gramas'), (4, 9, 200, 'gramas'),
          (5, 1, 20, 'gramas'), (5, 2, 1, 'quilo'), (5, 3, 0.200, 'litros'), (5, 4, 5, 'unidades'), (5, 5, 12, 'gramas'), (5, 6, 25, 'gramas'), (5, 7, 280, 'gramas'), (5, 10, 400, 'gramas'), (5, 11, 6, 'unidades'), (5, 12, 6, 'unidades'), (5, 13, 10, 'gramas'), (5, 14, 400, 'gramas'),
          (6, 1, 20, 'gramas'), (6, 2, 1, 'quilo'), (6, 3, 0.200, 'litros'), (6, 4, 5, 'unidades'), (6, 5, 12, 'gramas'), (6, 6, 25, 'gramas'), (6, 7, 280, 'gramas'), (6, 10, 400, 'gramas'), (6, 11, 6, 'unidades'), (6, 12, 6, 'unidades'), (6, 13, 10, 'gramas'), (6, 15, 400, 'gramas')
    ;

-- consultations
  create or replace view products_categories
    as
    select name_product, category_product
      from products inner join categories 
        on code_category = code_category_pk
  ;

  select *
    from products_categories
  ;

  create or replace view products_by_category
    as
    select category_product, count(amount_products) as amount
      from products inner join categories 
        on code_category = code_category_pk
      group by category_product
  ;

  select *
    from products_by_category
  ;

  create or replace view recipe
    as
    select name_product, name_ingredient, amount_ingredient, unity_ingredient
      from products inner join products_ingredients
        on code_product = code_product_fk inner join ingredients
        on code_ingredient = code_ingredient_fk
  ;

  select *
    from recipe
  ;

  create or replace view recent_products
    as
    select name_product, date_product
      from products
        where date_product >= current_date - 30
    order by date_product desc
  ;

  select *
    from recent_products
  ;

  create or replace view doubling_production
    as
    select name_ingredient, (2 * sum(amount_ingredient)) as forecast , unity_ingredient
      from ingredients inner join products_ingredients
        on code_ingredient = code_ingredient_fk
      group by name_ingredient, unity_ingredient
  ;

  select *
    from doubling_production
  ;

  create or replace view unused_product
    as
    select name_ingredient
      from ingredients
      where not exists
      (select *
        from products_ingredients
        where code_ingredient = code_ingredient_fk)
  ;

  select *
    from unused_product
  ;
