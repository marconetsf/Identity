# Identity
Biblioteca com as principais funções de padronização de identidade dos dispositivos Autocom Network

![logoinstaPreto](https://user-images.githubusercontent.com/37492251/96631249-72a61180-12ec-11eb-9e36-5902f3db2d9c.png)

Para utilizar esta biblioteca é necessário instalar algumas bibliotecas em Documentos/Arduino/libraries
 * [WiFiManager] - Biblioteca responsável por um autoconnect do dispositivo
 * [Core ESP8266] - Json a ser adicionado às preferências para instalar as placas ESP8266
 
 [WiFiManager]: <https://github.com/tzapu/WiFiManager.git>
 [Core ESP8266]: <https://arduino.esp8266.com/stable/package_esp8266com_index.json>
 
 ### Documentação
 
 ```sh
objeto.configMode();
```

# Modo configuração
- O modo configuração se trata do modo pré atuação do dispositivo, ou seja, ele será genérico para todos os dispositvos, logo consiste na seguinte sequência;
-> Conectar à internet através do WiFiManager (em caso de primeiro acesso, o dispositivo entra em modo AP sem password e você é automaticamente redirecionado para um HTML de condiguração no ip http://192.168.4.1 onde a própria biblioteca escaneia todas as redes locais e possibilita que você adentre com a senha de acesso)
Working in progress

