console.log (person && person.location && person.location.city);

if (onError) { 
  onError (mensagem de erro); 
}

Fazer verificações de potencial undefinedou nullvalores como esse desorganiza desnecessariamente seu código

console.log (pessoa?.localização?.cidade);

Se algum dos valores na cadeia de propriedades for undefinedor null, em vez de TypeError ser lançado, undefinedserá registrado no console!

onError? (mensagem de erro);

Você pode usar o encadeamento opcional para funções potencialmente indefinidas! Isso é especialmente útil para retornos de chamada. Se onErroré undefinedou null, nada acontece!

Esse recurso permite a leitura do valor de uma propriedade localizada profundamente dentro de uma cadeia de objetos conectados sem ter que validar expressamente que cada referência na cadeia é válida.
