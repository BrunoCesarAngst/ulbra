# Classes, que atuam como molde de objetos possibilitando a criação de objetos já incluindo alguns métodos.
class Product

  # Initialize é um método Ruby especial, chamado (construtor) quando você cria um objeto Ruby. Você o usa para configurar os valores iniciais.
  def initialize (name, weight, price, quantity, sector)
    @name = name
    @weight = weight
    @price = price
    @quantity = quantity
    @sector = sector
  end

  # Esse método será chamado para mostrar cada produto.
  def show()
    puts "Produto: #{@name}, Peso liquido: #{@weight}, Valor: #{@price.to_f}, quantidade em estoque: #{@quantity}, Setor: #{@sector}"
  end  

  # Esse método será chamado para dar o valor total em estoque de cada produto.
  def multiply()
    @result = @price*@quantity
    puts "O valor total de #{@name} em estoque é de R$ #{@result.to_f}"
  end
end
