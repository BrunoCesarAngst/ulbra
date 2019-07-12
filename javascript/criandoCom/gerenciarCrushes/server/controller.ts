import model from './model';

class Controller {

    constructor(){}

    //select
    getCrushes(){
        return model.find({});
    }

    select(req, res){
        this.getCrushes()
        .then(crushes => res.status(200).json({'result': crushes}))
        .catch(err => res.status(400).json({'result': err}));
    }

    //selectOne
    getCrushesById(id){
        return model.find(id);
    }

    selectOne(req, res){
        const id = {_id: req.params.id}

        this.getCrushesById(id)
        .then(crushes => res.status(200).json({'result': crushes}))
        .catch(err => res.status(400).json({'result': err}));
    }

    //delete
    deleteById(id){
        return model.deleteOne(id);
    }

    delete(req, res){
        const id = {_id: req.params.id}

        this.deleteById(id)
        .then(crushes => res.status(200).json({'result': crushes}))
        .catch(err => res.status(400).json({'result': err}));
    }

    //update
    updateCrush(id, data){
        return model.findOneAndUpdate(id, data);
    }

    update(req, res){
        const id = {_id: req.params.id}
        const crush = req.body;

        this.updateCrush(id, crush)
        .then(crushes => res.status(200).json({'result': crushes}))
        .catch(err => res.status(400).json({'result': err}));
    }

    //insert
    createCrush(data){
        return model.create(data);
    }

    insert(req, res){
        const crush = req.body;

        this.createCrush(crush)
        .then(crushes => res.status(200).json({'result': crushes}))
        .catch(err => res.status(400).json({'result': err}));
    }

}

export default Controller;
