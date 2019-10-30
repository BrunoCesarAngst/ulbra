# coding: UTF-8

agenda = {
  Ana: '11 111 111 111',
  Pedro:'22 222 222 222'
}

while true
  puts ''
  puts '1 - Adicionar'
  puts '2 - Atualizar'
  puts '3 - Exibir'
  puts '4 - Excluir'

  print 'Escolha uma opção: '
  escolha = gets.chomp
  puts ''
  
  case escolha
  when '1'
    print 'Nome do novo contato: '
    nome = gets.chomp
    if agenda[nome.to_sym].nil?
      print 'Insira o telefone: '
      telefone = gets.chomp
      agenda[nome.to_sym] = telefone
    else
      puts 'Este nome já existe!'
    end
  when '2'
    print 'Quem você deseja atualizar: '
    nome = gets.chomp
    if agenda[nome.to_sym].nil?
      puts 'Este nome já existe!'
    else
      print 'Qual o telefone: '
      telefone = gets.chomp
      agenda[nome.to_sym] = telefone
    end
    when '3'
      agenda.each do |nome, telefone|
        puts "Nome: #{nome} - Telefone: #{telefone}"
      end
    when '4'
      print 'Excluir qual contato? '
      nome = gets.chomp
      if agenda[nome.to_sym].nil?
        puts 'Este nome não existe!'
      else
        agenda.delete(nome.to_sym)
        puts "#{nome} foi deletado."
      end
    else
      puts 'Desculpa, opção inválida!!!'
    end
end
