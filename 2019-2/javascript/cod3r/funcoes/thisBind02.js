function Pessoa() {
    this.idade = 0

    setInterval(function(){
        this.idade++ //o this.idade não aponta para o objeto pessoa, pois quem esta disparando e não o obejeto Pessoa
        console.log(this.idade)
    }, 1000)
}
new Pessoa
//#region
function Pessoa2() {
    this.idade = 0

    setInterval(function(){
        this.idade++
        console.log(this.idade)
    }.bind(this), 1000)
}
new Pessoa2
//#region

function Pessoa3() {
    this.idade = 0

    const self = this
    setInterval(function(){
        self.idade++
        console.log(self.idade)
    }, 1000)
}
new Pessoa3