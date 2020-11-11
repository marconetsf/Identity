# Identity
Biblioteca com as principais funções de padronização de identidade dos dispositivos.

Para utilizar esta biblioteca é necessário instalar algumas bibliotecas em Documentos/Arduino/libraries
 * [WiFiManager] - Biblioteca responsável por um autoconnect do dispositivo
 * [Core ESP8266] - Json a ser adicionado às preferências para instalar as placas ESP8266
 
 [WiFiManager]: <https://github.com/tzapu/WiFiManager.git>
 [Core ESP8266]: <https://arduino.esp8266.com/stable/package_esp8266com_index.json>
 
 # Documentação
 

## Modo configuração

 ```sh
objeto.configMode();
```

- O modo configuração se trata do modo pré atuação do dispositivo, ou seja, ele será genérico para todos os dispositvos, logo consiste na seguinte sequência;

-> Conectar à internet através do WiFiManager (em caso de primeiro acesso, o dispositivo entra em modo AP (o nome da rede é o MAC do dispositivo) sem password e você é automaticamente redirecionado para um HTML de condiguração no ip http://192.168.4.1 onde a própria biblioteca escaneia todas as redes locais e possibilita que você adentre com a senha de acesso). Uma vez configurada a rede a própria biblioteca salva as informações na EEPROM até que a rede não esteja mais disponível.

-> Após a conexão com a internet a ESP8266 é reinicializada em modo WebServer e um mdns de acesso que consiste no http://mac_do_dispositivo.local

-> Ele irá aguaradar até que alguém acesse a página ttp://mac_do_dispositivo.local/id/defineID=<id de configuração> no qual o sistema de interface e gerenciamento quem irá definir esse id com base na quantidade de dispositivos já pré configurados.

-> Tendo posse do id do dispositivo, ele armazena essas informações na EEPROM e reinicializa no modo de ação normal.


## Reset do dispositivo

```sh
objeto.resetDisp();
```

- Reseta os as conexões de rede anteriores da memória. Ele também faz a ESP8266 Reiniciar, então não é interessante mante-lo no workflow de execução onde ele é acionado de forma procedural. 

## Acesso ao Id do dispositivo

```sh
objeto.getStrID();
```

```sh
objeto.getCharID();
```

- Esta função retorna em string ou em Char o id do dispositivo.

## Acesso ao endereço MAC do dispositivo

```sh
objeto.getMAC();
```

- Esta função retorna em string o endereço MAC do dispositivo.

## Setar Tópico

```sh
objeto.setTopic(String topic)
```

- Esta função serve para inserir o ID do dispositivo dentro do tópico armazenado em formato de string em uma variável, essa função pode ser utilizada diretamente dentro da função client.publish ou client.substcribe da biblioteca pubsupclient.h
