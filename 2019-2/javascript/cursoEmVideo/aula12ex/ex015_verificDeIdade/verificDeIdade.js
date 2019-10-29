function verificar() {
    var data = new Date()
    var ano = data.getFullYear() // ano atual
    var formularioAno = document.getElementById('txtAno')
    // var res = document.getElementById('res')
    var res = document.querySelector('div#res') // por seletor de css
    if (formularioAno.value.length == 0 || Number(formularioAno.value) > ano) {
        window.alert('[ERRO] Verifique os dados e tente novamente!!!')
    } else {
        var formularioSexo = document.getElementsByName('radSex')
        var idade = ano - Number(formularioAno.value)
        // res.innerHTML = `idade calculada ${idade}`// só para testar.
        var genero = ''

        // criando img do html dinamicamente
        var img = document.createElement('img')
        img.setAttribute('id', 'foto')

        if (formularioSexo[0].checked) {
            genero = 'Homem'
            if (idade >= 0 && idade < 10) {
                //criança
                img.setAttribute('src','verificDeIdade/menino.jpg')
            } else if (idade < 21) {
                //jovem
                img.setAttribute('src', 'verificDeIdade/umJovem.jpg')
            } else if (idade < 50) {
                //adulto
                img.setAttribute('src', 'verificDeIdade/homem.jpg')
            } else {
                //idoso
                img.setAttribute('src', 'verificDeIdade/senhor.jpg')
            }
        } else if (formularioSexo[1].checked) {
            genero = 'Mulher'
            if (idade >= 0 && idade < 10) {
                //criança
                img.setAttribute('src', 'verificDeIdade/menina.jpg')
            } else if (idade < 21) {
                //jovem
                img.setAttribute('src', 'verificDeIdade/umaJovem.jpg')
            } else if (idade < 50) {
                //adulta
                img.setAttribute('src', 'verificDeIdade/mulher.jpg')
            } else {
                //idosa
                img.setAttribute('src', 'verificDeIdade/senhora.jpg')
            }
        }
        res.style.textAlign = 'center'
        res.innerHTML = `Detectamos ${genero} com ${idade} anos!`
        res.appendChild(img)
    }
}