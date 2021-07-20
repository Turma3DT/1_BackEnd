const express = require('express')
const router = express.Router();


const getVelocidadeController = require('./Controllers/getVelocidadeController');
const getStatusController = require('./Controllers/getStatusController')
const getSensoresController = require('./Controllers/getSensoresController')


router.get('/status', getStatusController.get);
router.get('/velocidade', getVelocidadeController.get);
router.get('/sensores', getSensoresController.get);


module.exports = router;




