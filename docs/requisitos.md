# Servidor Distribuído

1. Monitorar entradas (botões e sensores) - Polling ou Interrupções
2. Receber comandos TCP/IP do servidor central - Thread
3. Controlar o temporizador dos semáforos

Sugestão: desacoplar o código em módulos (camada de controle, rede, monitoramento)

# Temporizador

|          | Principal | Auxiliar |
|:--------:|:---------:|:--------:|
|   Verde  |   10/20   |   5/10   |
|  Amarelo |     3     |     3    |
| Vermelho |    5/10   |   10/20  |