//  1º Inicia-se importando o express colocando tudo que a depedência
// 'express' exporta ou expoem de funcionalidade, que estará presente na
// variável const express, e com a função require passasse o nome da
// depedência que se está importando para dentro do arquivo
const express = require('express')

//  2º Para instaciar ou iniciar a aplicação criasse uma variável app ou server
// recebendo a função express, chamando a função do express.
const server = express()

// 8.a adicionamos um plugin um modulo o 'use' a instância da aplicação o
// server, pois, esse modulo plugin que entende json já esta lá dentro do 
// express que importamos
server.use(express.json())

// 4º Criasse a primeira rota fazendo uso de um metodo HTTP(get, post, put
// ou delete). Com o metodo get é possível testar direto no navegador pois
// é por esse metodo que os navegadores acessam os endereços de pesquisa, por
// exemplo quando o usuario acessar a rotar http://localhost:3000/users,
// passasse uma função que diz o que o codigo pracisa fazer quando esse
// endereço ou rota for acessada. 
// server.get('/users', () => {
  // Usando o comando console.log com um users para realmente testar, rodasse
  // no terminal o arquivo com o comando node index.js que ficará executando o
  // script dentro do terminal(sendo somente interrompido com ctrl c), depois
  // acessando no browser o endereço http://localhost:3000/users, no momento
  // que for recaregada a página, a página também ficará rodando e no terminal
  // será mostrado o users.
  // console.log((1 + 2) + ' users')
// })
// Para que o navegador não fique em lop infinito temos que definir o que o
// frontend deve mostrar, retornando uma resposta, então toda a função que é
// passada como segundo parametro do server .get que é como a rota vai ser
// manipulada, ela sempre receberá dois parametros req e res.
// req é todos os dados de nossa requisição podendo o usuário enviar
// paramatros pela/para rota que podem ser tanto queryParams que são enviados
// assim '/users?' ou routeParams que são enviados direto na url assim 
// '/users/1' e nos casos de post e put são enviados o body, o corpo da
// requisição que é o request body, tudo isso estará dentro do req.
// Já dentro do res temos todas as informaçãoes para retornar uma resposta
// para o meu cliente o meu frontend

// 6º No req temos três tipos de parametros
// Query params = ?users=1
// Route params = /users/1
// Request body = {  } que vem nos posts e puts, que são os pem loads as
// informações para criar/alterar usuário
// Então vamos buscar essas informações dentro do req
// consumindo os Query params
// supondo que na rota users no browser seja passado o seguinte endereço
// http://localhost:3000/users?nome=Bruno, para mostrar a mensagem 'Hello
// Bruno'
// server.get('/users', (req, res) => {
  // para isso é definida um variável 
  // const nome = req.query.nome
  // e altero o valor da mensagem para template strings
  // return res.json({ massage: `Hello ${nome}` })
  // reiniciando o servidor aparecerá como retorno de resposta
  // {"massage":"Hello Bruno"}
// })
// consumindo os Route params
// supondo que na rota users no browser seja passado o seguinte endereço
// http://localhost:3000/users/3, para mostrar a mensagem
// 'Buscando o usuário 3'
// server.get('/users/:id', (req, res) => {  
  // para isso é definida um variável 
  // const id = req.params.id
  // podemos usar a desestruração botando o id dentro de um objeto {  }
  // simbolizando que quero pegar o id, ficando mais simples
  // const { id } = req.params
  // e altero o valor da mensagem para template strings
  // return res.json({ message: `Buscando o usuário ${id}` })
  // reiniciando o servidor aparecerá como retorno de resposta
  // {"message":"Buscando o usuário 3"}
// })

// 7º Antes de começar a criar rotas de post, get, put e delete, fazendo uso
// do insomnia vamos criar e testar essas rotas configurando as requests
// para não fazer uso de base de dados por enquanto e sabendo que toda vez que
// que executamos o node 'node index.js' todas as variáveis ficam guardadas na
// memoria e não são recriadas quando o usuário faz uma requisição vamos criar
// uma variável
// const users = ['Benjamin', 'Micaela', 'Margarete', 'Bruno']
// e especificamos passada como segundo parametro do server .get que é como a
// rota vai ser manipulada o '/users/:index'
// server.get('/users/:index', (req, res) => {  
  // para isso é definida um variável 
  // podemos usar a desestruração botando o index dentro de um objeto {  }
  // simbolizando que quero pegar o index, ficando mais simples
  // const { index } = req.params
  // passando users[index] para ser o retorno
  // return res.json(users[index])
  // reiniciando o servidor aparecerá como retorno de resposta, conforme 
  // a alteração do index: 0, 1 e 2 - 'Micaela', 'Margarete', 'Bruno'
  // para deixar essa parte de execução e reinicialização da aplicação mais
  // automática após alterações, vamos instalar uma dependência
  // 'yarn add nodemon -D', a flag -D é para instalar em modo de
  // desenvolvimento para não subir em modo de produção, pois, ela não vai ser
  // utilizada quando for on-line, pois não é preciso moniturando arquivos
  // para executar o nodemon podemos executar na linha de comando
  // yarn nodemon index.js, mas, é mais produtivo criar um propriedade chamada
  // scripts no package.json, após license - "scripts": {"dev":"nodemon index.js"},
// })

// 8º Continua - Partindo então para a parte do CRUD - Create, Read, Update e
// Delete
const users = ['Benjamin', 'Micaela', 'Margarete', 'Bruno']

// 9º Middlewares é a base de toda a plicação, uma função que recebe os
// parametros req, res e outros e faz alguma coisa dentro da aplicação
// manipulando os resultados de alguma forma. Então tudo que vem como segundo
// parametro depois dos métodos são middlewares.
// Criamos um middleware global, que indepente da rota chamada esse middleware
// sempre será chamado e para que essa middleware global não fique bloqueando
// os outros métodos, pois, o middleware é um interceptador que pode bloquear
// uma rota para algum fim expecífico, é pasado um terceiro parametro, uma
// função que se chama next
server.use((req, res, next) => {
  // 9.a
  console.time('Request') // calcula o tempo de execução de uma instrução de
  // código e altero o console.log('Finalizado') para
  // console.timeEnd('Finalizado')
  console.log(`Método: ${req.method}; URL: ${req.url}`)
  // criou-se um middleware de log da aplicação, para saber todas as rotas
  // chamadas dentro do insomnia

  // return next()
  // o middleware depois de chamar a função next ele não tem mais a
  // obrigatoriedade de executar mais nada (pode- se continuar executando mais
  // coisas), então tiramos o return
  next()
  // incluimos um então
  // console.log('Finalizado') que só vai ser executado depois do next que é o
  // ultro middleware que está dentro da rota e para verificar isso criamos 9.a
  console.timeEnd('Request') // pasando o mesmo nome continua
})

// Criando middleware local para verificar a existência das informações pasadas
function checkUserExists(req, res, next) {
  if (!req.body.name) { // esse middleware vai no corpo da minha requisição
    // procurar se existe a informação name passada se ele não encontrar
    // retorna esse erro
    return res.status(400).json({ error: 'User name is required!'})
    // se ele achar então ...    
  }
  return next()
    // para utilizar esse middleware nas rotas necessárias é só pegar o nome
    // dessa função e colar nas rotas após a primeira virgula, colocando
    // quantas middleware necesssárias for
}

// Criando um middleware que verifica o index informado
function checkUserInArray(req, res, next) {
  // middlewares podem alterar as variáveis req e res, principalmente a req  
  const user = users[req.params.index]

  if (!user) {
    return res.status(400).json({ error: 'User does not exists!'})
  }
  // vamos a um exemplo, quando checkUserInArray encontra o usuário
  req.user = user
  // é adicionada uma nova variável ao req. Então toda rota que usa essa middleware com a função checkUserInArray tem acesso as informações dessa
  // variável, a ponto de poder alterar a rota get '/users/:index'
  return next()
}

// 8º continuação - Primeiramente criaremos uma rota que lista todos os
// usuários
server.get('/users', (req, res) => {
  return res.json(users)
})
// e especificamos passada como segundo parametro do server .get que é como a
// rota vai ser manipulada o '/users/:index'
server.get('/users/:index', checkUserInArray, (req, res) => {
  // por fazer uso da função checkUserInArray, posso deletar vou só comentar
  // a variável 
  // const { index } = req.params, sendo desnecessário pegar a index
  // substituindo o return
  // return res.json(users[index])  
  return res.json(req.user) 
  // pois req.user já vai ter o usuário que está acessando o
  // users[req.params.index] 
})
// Criamos a rota de criação com metodo post
server.post('/users', checkUserExists, (req, res) => {
  // agora presisamos pegar o nome do usuário que queremos criar e essa
  // informação vem pelo Request body, pelo corpo da requisição, então dentro
  // do insomnia como usuario vamos passar uma propriedade com uma variável
  // name e dentro dela o nome do usuário então pegamos a variável name de
  // dentro do req.body
  const { name } = req.body
  // o users é um array e jogo coisas dentro com o método push 
  users.push(name)
  // fazendo um retorno dessa entrada de dados
  return res.json(users)
  // vou para o insomnia e crio uma nova requisição com metodo post e corpo em
  // formato de json, quando então for iserir o usuario no insomnia em formato
  // json vai dar erro, pois, o express tem várias formas de receber
  // informações  como Request body (corpo da requisição) uma delas utilizando
  // json e é um padrão para a maioria dos projetos, precisamos avisar o
  // express, para e ler json do corpo de nossa requisição detalhe no 8.a 
})

// Criamos a rota de alteração com metodo put
// agora precisamos do Routes params que vai receber o index do usuario que
// quero modificar procurando dentro do meu array o usuário que eu quero
// modificar
server.put('/users/:index', checkUserInArray, checkUserExists, (req, res) => {
  // Vou no vetor encontro a posição que estou recebendo na rota :index
  const { index } =req.params
  // recebo o novo nome no corpo da requisição
  const { name } = req.body
  // e sobreponho ao nome do index requerido o novo nome que está sendo passado
  users[index] = name
  // então retorno todos os usuários via json
  return res.json(users)
})

// deletar
server.delete('/users/:index', checkUserInArray, (req, res) =>{
  const { index } = req.params

  users.splice(index, 1)
  // dentro do vetor (users) e com o metodo splice, que percore até a index
  // passada cortando as tantas posições pasadas através do número, cortando
  // uma posição do index

  // no metodo delete não há necessidade de retornar todos os usuários após
  // uma exclusão, só precisamos saber que deu tudo certo retornando somente
  // um  status code
  // return res.json(users)
  return res.send()
})

// server.get('/users', (req, res) => {
  // 5º como aqui não estamos recebendo nenhum parametro na minha requisição
  // utilizo então o res para retornar uma resposta para o cliente com
  // com res.send que retorna um texto na resposta
  // return res.send('Hello World')
  // ou com res.json que retorna um estrura de dados um json, pois, dentro
  // contem um objeto "{  }"
  // return res.json({ massage: 'Hello World' })
// })

// 3º Como se astá criando um servidor com o node uma api, esse servidor deve
// ouvir alguma porta, para quando for acessado o http://localhost:3000
// esse servidor seja chamado
server.listen(3000)
