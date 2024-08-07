// parte 1 - requisicao que se conecta noa API do chatGPT

// import OpenAI from "openai";

//     const openai = new OpenAI({
//         organization: "",
//         apiKey: "",
//     })

//     const chatCompletion = await openai.chat.completions.create({
//         model: 'gpt-3.5-turbo',
//         messages: [{'role': 'user', 'content': 'quem e voce?' }]
//     })

//     console.log(chatCompletion.choices[0].message)

// parte 2 - cria o backend completo com api local

import OpenAI from "openai";
import express from 'express';
import bodyParser from "body-parser";
import cors from 'cors'

// aki vc troca para o gemini
const openai = new OpenAI({
    organization:"",
    apiKey: "",
})

// criar o back end apartir daqui

const app = express();
const port = 3000;

app.use(bodyParser.json())
app.use(cors())

// criando end point para enviar mensagens a api do chat gpt

app.post('/sendMessage', async(req, res) => {
    const {message} = req.body; // o que veio do front

    // aki vc troca para o gemini
    const chatCompletion = await openai.chat.completions.create({
        model: 'gpt-3.5-turbo',
        messages: [
            {'role': 'user', 'content': 'Você sera o Dale Carnegie' },
            ...messages
        ]
    })
    
    console.log(chatCompletion.choices[0].message);

    // e a resposta que vu retornar para o front end
    // isso so e possivel pq to fazendo via metodo post
    res.json({
        chat_completion: chatCompletion.choices[0]
    })
})

app.listen(port, () => {
    console.log(`servidor aberto execultando em http://localhost:${port}/`)
})

// para execultar o arquivo js
// entra na pasta
// node 'nome do arquivo' 