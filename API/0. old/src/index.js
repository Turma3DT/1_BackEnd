const express = require('express');
require('dotenv').config();
const router = require('./routes');
const cors = require('cors');
const app = express();


app.use(express.urlencoded({ extended: true })); 
app.use(express.json());
app.use(cors());

app
    .use('/', router);

app.listen(process.env.PORT,  () => {
    console.log(`A api esta rodando em http://localhost:${process.env.PORT}`);
});