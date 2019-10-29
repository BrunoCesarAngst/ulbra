const express = require('express')
const bodyParser = require('body-parser')

const app = express()

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extends: false }))

app.get('/', (req, res) => {
  res.send('Funcionando')
})

const rotas = require('./rotas')
app.use('/api', rotas)

app.use(express.static(__dirname + '/client'))

const port = 3001

app.listen(port, () => {
  console.log('servidor rodando em http://localhost:',port)
})
