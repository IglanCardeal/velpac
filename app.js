const PORT = process.env.PORT || 3000;

const express = require('express');
const cors = require('cors');
const path = require('path');

const app = express();
const router = express.Router();

app.set('view engine', 'ejs');
app.set('views', './frontend/');

app.disable('x-powered-by');

app.use(cors({
  origin: true
}));

app.use(express.static(path.join(__dirname, 'frontend', 'public')));

app.use(
  router.get('/', (req, res) => {
    res.render('views/index');
  }),
);

app.use(
  router.get('/pdf/documentacao', (req, res) => {
    const path = __dirname + '/frontend/public/documents/documentacao.pdf';
    res.sendFile(path);
  }),
);

app.use(
  router.get('/img/projeto', (req, res) => {
    const path = __dirname + '/frontend/public/img/projeto/projeto.zip';
    res.sendFile(path);
  }),
);

app.use(
  router.get('/img/arduino', (req, res) => {
    const path =
      __dirname + '/frontend/public/img/projeto/arduino-code-prototype.zip';
    res.sendFile(path);
  }),
);

app.use((req, res) => {
  res.redirect('/');
});

app.listen(PORT, () => {
  console.log(`
================== ENV: ${process.env.NODE_ENV} ======================
Servidor ONLINE. Porta: ${PORT}
http://localhost:${PORT}
`);
});
