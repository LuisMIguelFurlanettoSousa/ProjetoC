# 🔐 Gerador de Senhas em C

Um simples e funcional **gerador e gerenciador de senhas em C**, feito para criar senhas seguras com base nas escolhas do usuário. Ideal para praticar estruturas, vetores, strings e manipulação básica de dados em C.

---

## 📋 Funcionalidades

- Gerar senhas com:
  - Apenas **números**
  - Apenas **letras**
  - **Números + letras**
  - **Números + letras + caracteres especiais**
- Armazenar até **5 senhas** com nomes personalizados
- Exibir todas as senhas geradas
- Apagar senhas específicas
- Interface via terminal (menu interativo)

---

## 🚀 Como usar

1. Compile o programa:

   ```bash
   gcc gerador_senhas.c -o gerador_senhas

    Execute no terminal:

    ./gerador_senhas

    Siga o menu interativo para gerar, visualizar ou apagar senhas.

💡 Exemplo de uso

=== Gerador de Senhas ===
1. Gerar senha com apenas numeros
2. Gerar senha com apenas letras
3. Gerar senha com numeros e letras
4. Gerar senha com numeros, letras e caracteres especiais
5. Exibir as senhas geradas
6. Apagar uma senha
7. Sair
Escolha uma opcao: 3
Informe o tamanho da senha: 10
Informe o nome para esta senha: GitHub
Senha gerada: a9Ld7vBzXq

🛠️ Tecnologias

    Linguagem: C

    Bibliotecas utilizadas:

        stdio.h

        stdlib.h

        time.h

        string.h

📦 Estrutura do Código

    main() → Loop principal com menu e controle de opções

    gerarSenha() → Geração aleatória de senhas com base nos critérios

    menu() → Exibe o menu principal

    apagarSenha() → Exclui uma senha do vetor
