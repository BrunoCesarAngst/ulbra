function carregar() {
    var msg = window.document.getElementById('msg');
    var img = window.document.getElementById('foto');
    var data = new Date();
    var hora = data.getHours();
    //var hora = 22;
    msg.innerHTML = `Agora são ${hora} hs.`;

    if (hora >= 0 && hora < 12) {
        img.src = 'horaDoDia/manha.png';
        window.document.body.style.background = '#FE9400';
    } else if (hora >= 12 && hora < 18) {
        img.src = 'horaDoDia/tarde.png';
        window.document.body.style.background = '#FCBDB6';
    } else {
        img.src = 'horaDoDia/noite.png';
        window.document.body.style.background = '#190F31';
    }
}
