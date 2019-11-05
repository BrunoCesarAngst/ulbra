# Aqui estou trazendo o objeto e os métodos, criados no arquivo product.rb
require_relative "product"

class Commands
  def initialize
    answer = 's' # Atribuindo um valor para uma variável.
    @stock = []  # Criando um array para armazenar os produtos cadastrados
    
    # Um laço para cadastras produtos quanto necessário.
    while answer != 'n'     
      puts 'Cadastro de produtos (somente valores)'      
      print 'Digite o nome do produto: '
      productName = gets.chomp # Recebe o valor e remove o \0.
      print 'Digite o peso liquido do produto: '
      productWeight = gets.chomp        
      print 'Digite o valor unitário do produto: R$ '
      productPrice = gets.chomp.to_f # Converte para float
      print 'Digite a quantidade em estoque: '
      productQuantity = gets.chomp.to_i # Converte para integer
      print 'Digite o setor do produto: '
      sectorName = gets.chomp
      print 'continuar (s/n)? '
      answer = gets.chomp

      # Uma variável instanciada que recebe um novo produto.
      @product = Product.new(productName, productWeight, productPrice, productQuantity, sectorName)

      # Esse método push está empurrando o novo produto para a array estoque.
      @stock.push(@product)
      
      # Aqui testamos a reposta do usuário.
      if answer == 'n'
        break
      end
    end 
    
    puts "-----------\n"
    # Para cada produto no array estoque mostre o produto.
    @stock.each do |product|
      product.show
    end
    puts "-----------\n"
    # Para cada produto no array estoque dê o valor total de cada produto.
    @stock.each do |product|
      product.multiply
    end
    puts "-----------\n"
  end
end
Commands.new
