const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const routes = require('./routes');

const server = express();

mongoose.connect('mongodb+srv://root:4n657@cluster0-uinlh.mongodb.net/omnistack8?retryWrites=true&w=majority', {useNewUrlParser: true});


server.use(cors());
server.use(express.json());
server.use(routes);

server.listen(1234);
