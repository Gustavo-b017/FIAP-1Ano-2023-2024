npm init
npm i express body-parser cors
npm i openai@^4.0.0

packge.json, adiciona na linha 6:
    "type": "module",

cria e configura o index.js:
    import OpenAI from "openai";

    const openai = new OpenAI({
        organization: "",
        apiKey: "",
    })

    const chatCompletion = await openai.chat.completions.create({
        model: 'gpt-3.5-turbo',
        messages: [{'role': 'user', 'content': 'quem e voce?' }]
    })

    console.log(chatCompletion.choices[0].message)

manda no terminal:
    nome.index.js