letra = "X"

function jogar(celula){
    celulaclicada = document.getElementById(celula).innerHTML;
   if (celulaclicada == "X" || celulaclicada == "O"){
       alert("Opa, este quadrado já foi escolhido!")
   }else{
        document.getElementById(celula).innerHTML = letra
        if (letra == "X"){
            letra = "O"
        }else{
            letra = "X"
        }
   }
}

function verificarTrinca(){
   c11 = document.getElementById('cel11').innerHTML
   c12 = document.getElementById('cel12').innerHTML
   c13 = document.getElementById('cel13').innerHTML
   c21 = document.getElementById('cel21').innerHTML
   c22 = document.getElementById('cel22').innerHTML
   c23 = document.getElementById('cel23').innerHTML
   c31 = document.getElementById('cel31').innerHTML
   c32 = document.getElementById('cel32').innerHTML
   c33 = document.getElementById('cel33').innerHTML
   if (((c11 != '') && (c12 != '') && (c13 != '') && (c11 == c12) && (c12 == c13)) || ((c11 != '') && (c22 != '') && (c33 != '') && (c11 == c22) && (c22 == c33)) || ((c11 != '') && (c21 != '') && (c31 != '') && (c11 == c21) && (c21 == c31)) || ((c21 != '') && (c22 != '') && (c23 != '') && (c21 == c22) && (c22 == c23)) || ((c31 != '') && (c32 != '') && (c33 != '') && (c31 == c32) && (c32 == c33)) || ((c12 != '') && (c22 != '') && (c32 != '') && (c12 == c22) && (c22 == c32)) || ((c13 != '') && (c23 != '') && (c33 != '') && (c13 == c23) && (c23 == c33)) || ((c31 != '') && (c22 != '') && (c13 != '') && (c31 == c22) && (c22 == c13))){
       alert('Você ganhou! Parabéns campeão!')
      iniciarNovoJogo()
   }
}

function iniciarNovoJogo(){
    for (i=1; i<4; i++){
		for (j=1; j<4; j++){
    		nomecelula = 'cel' + i + j
			document.getElementById(nomecelula).innerHTML = ''
		}
	}
}
