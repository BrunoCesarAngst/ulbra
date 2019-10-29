const express = require('express')
const router = express.Router()

router.get('/comentarios/:postid', (req, res) => {
  res.json({
    conteudo: 'Ouça bem...!!!',
    autor: 'Bruno César Angst',
  })
})

module.exports = router
