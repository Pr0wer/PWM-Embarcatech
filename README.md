# CONTROLE DE SERVO MOTOR COM PWM

# Visão geral do programa
Consiste na utilização da biblioteca Pico SDK para controlar um servomotor a partir do PWM (Pulse Width Modulation), por meio de diferentes valores referentes a angulações dele. Inicialmente, ele assume as posições dos ângulos 180*, 90* e 0* e depois executa um movimento periódico, suave, entre os ângulos 0* e 180*

# Como usar?
Para usar o programa apresentado, deve se utilizar ou a plataforma [Wokwi](https://wokwi.com/) ou um microcontrolador Raspberry Pi Pico W, ao utilizar em ambos, com os devidos cuidados:
    
* 1 Servomotor (No GPIO 22 como definido por padrão no código, mas pode ser alterado)
  
Após a devida conexão, basta realizar os passos referentes ao modo desejado de execução do programa:

  # WOKWI 
  A nível de simulação, é necessário adicionar o código presente em "pwm.c" no [Wokwi](https://wokwi.com/) e executar.
  
  # RASPBERRY PI PICO W 
  Já a nivel de hardware, deve-se clonar o presente repositório ao executar o comando no diretório desejado: 
  
  ```git clone https://github.com/Pr0wer/PWM-Embarcatech.git```
  
  Em seguida, depois da instalação e configuração do Pico SDK e as variáveis de ambiente o usuário precisará executar o programa em uma IDE de preferência, que consiga compilar o código em C para um arquivo .uf2. Por fim, é só adicionar o arquivo .uf2 à memória flash de     seu Raspberry Pi Pico W. É recomendado a utilização da IDE [Visual Studio Code](https://code.visualstudio.com/) com a extensão Raspberry Pi Pico, visto que ela faz a instalação de todos os recursos necessários e permite compilar o código em pouquíssimos cliques.

  # ---------------
  Pronto! Na execução do programa, observe o servomotor assumir diferentes posições e executar um movimento periódico e suave.

  Vídeo com execução e explicação mais a fundo do código: https://www.youtube.com/watch?v=XqKRIwnmDH4
