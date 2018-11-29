
function enviardados(){

if(document.dados.tx_nome.value=="" || document.dados.tx_nome.value.length <= 6) //verifiquei presença de texto e condicionei número de caracteres.
{
alert( "Preencha seu nome completo!" );
document.dados.tx_nome.focus();
return false;
}

//var x = document.getElementById("meuRadio").checked;

//if (document.dados.meuRadio.checked = false)
//{
//alert("Selecione seu gênero");
//document.dados.txt_sexo.focus();
//return false;
//}

var genero;
if (document.getElementById("radioHomem").checked) {
	genero = "sr ";
} else if(document.getElementById("radioMulher").checked) {
	genero = "sra ";
} else {
	alert("Defina seu genero!");
}

if( document.dados.tx_email.value=="" || document.dados.tx_email.value.indexOf('@')==-1 || document.dados.tx_email.value.indexOf('.')==-1 )
{
alert( "Preencha campo E-MAIL corretamente!" );
document.dados.tx_email.focus();
return false;
}

if (document.dados.tx_mensagem.value=="")
{
alert( "Preencha o campo MENSAGEM!" );
document.dados.tx_mensagem.focus();
return false;
}

return true;
}
