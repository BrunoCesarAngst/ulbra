const express = require('express')
const router = express.Router()

router.get('/postagens', (req, res) => {
  res.json({
    titulo: 'Meu primeiro post',
    conteudo: 'Falando em falar!',
    autor: 'Bruno César Angst',
  })
})

module.exports = router
