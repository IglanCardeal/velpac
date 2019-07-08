const PORT = process.env.PORT || 3000;

import express from "express";
import path from "path";

const app = express();
const router = express.Router();

app.set("view engine", "ejs");
app.set("views", "./frontend/");
app.use(express.static(path.join(__dirname, "frontend", "public")));

app.use(
  router.get("/", (req, res) => {
    res.render("views/index");
  })
);

app.use(
  router.get("/pdf/documentacao", (req, res) => {
    const path = __dirname + "/frontend/public/documents/documentacao.pdf";
    res.sendFile(path);
  })
);

app.listen(PORT, () => {
  console.log(`
================== ENV: PRODUCAO ======================
Servidor ONLINE. Porta: ${PORT}
`);
});

