import * as mongoose from 'mongoose';

class DataBase {
    private dburi = 'mongodb://127.0.0.1/gerenciadorCrushes';
   private dbconnection;

    constructor(){ };

    createConnection(){
        mongoose.connect(this.dburi);
        this.logger(this.dburi);
    }

    logger(uri){
        this.dbconnection = mongoose.connection;
        this.dbconnection.on('connected', () => console.log('mongoose está conectado'));
        this.dbconnection.on('Error', error => console.error.bind('erro de conexão: ' + error));
    }
}

export default DataBase;
