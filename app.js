import dotenv from "dotenv";

dotenv.config();
const PORT = process.env.PORT || 3000;

import express from "express";
import path from "path";

// Rotas
import home from "./backend/routes/home";

const app = express();

app.set("view engine", "ejs");
app.set("views", "./frontend/");
app.use(express.static(path.join(__dirname, "frontend", "public")));

app.use(home);

app.listen(PORT, () => {
  console.log(`
================== ENV: ${process.env.APP_ENV} ======================
Servidor ONLINE. Porta: ${PORT}
`);
});
