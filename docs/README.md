Monitoramento Agrícola ESP32
Objetivo do Projeto
Este projeto visa criar um sistema inteligente de monitoramento agrícola utilizando o microcontrolador ESP32 e quatro sensores. O sistema coleta dados ambientais e toma decisões automatizadas para otimizar o uso de recursos, como irrigação e controle climático.

Sensores Utilizados
DHT22 (Umidade e Temperatura):

Mede a umidade e a temperatura do ambiente, ajustando a irrigação com base nesses valores.
Conexão: VCC ao 3.3V, GND ao GND, Data ao GPIO 15.
HC-SR04 (Ultrassom):

Mede a distância de líquidos em reservatórios de água, monitorando o nível de água disponível para irrigação.
Conexão: Trig ao GPIO 5, Echo ao GPIO 18, VCC ao 5V, GND ao GND.
PIR (Sensor de Movimento):

Detecta a presença de animais ou pessoas em áreas monitoradas, sendo útil para a segurança da fazenda.
Conexão: VCC ao 5V, GND ao GND, Data ao GPIO 4.
LDR (Sensor de Luz):

Monitora a intensidade da luz solar, permitindo ajustar a irrigação conforme a quantidade de luz recebida.
Conexão: VCC ao 3.3V, GND ao GND, Data ao GPIO 34.
Desenho do Circuito Completo
O circuito foi montado no simulador Wokwi. Abaixo segue o link para a simulação: Simulação no Wokwi

Como Configurar e Rodar o Projeto
Simulação no Wokwi
Acesse o link da simulação no Wokwi.
Pressione "Play" para iniciar a simulação do sistema de monitoramento.
Executar o Projeto Localmente com ESP32
Clone este repositório:
bash
Copiar código
git clone https://github.com/JoaoBeiro/Monitoramento-Agricola-ESP32.git
Carregue o código na sua placa ESP32 usando Arduino IDE ou VSCode com PlatformIO.
Instale as bibliotecas necessárias:
DHT.h
Ultrasonic.h
Bibliotecas Necessárias
Para rodar o projeto, você precisará das seguintes bibliotecas:

DHT: Para medir temperatura e umidade.
Ultrasonic: Para medir distância com o sensor HC-SR04. Você pode instalar as bibliotecas diretamente na Arduino IDE ou via PlatformIO.
Testes Realizados
Durante o desenvolvimento, foram realizados os seguintes testes:

Testes de temperatura e umidade:

O sensor DHT22 mediu a temperatura e umidade com precisão, ajustando a irrigação de acordo com os parâmetros definidos.
Testes de nível de água:

O sensor HC-SR04 mediu o nível de água e acionou a irrigação automaticamente quando o nível estava baixo.
Testes de movimento:

O sensor PIR detectou a presença de movimento de maneira confiável.
Testes de luminosidade:

O sensor LDR ajustou a irrigação conforme a quantidade de luz solar.
Prints do Sistema em Funcionamento
Os resultados dos testes podem ser visualizados na pasta /tests onde prints do Monitor Serial foram armazenados.

Contribuições
Para contribuir com o projeto:

Crie uma branch própria a partir da branch develop.
Envie uma Pull Request com suas alterações.
Revise o código antes de submeter o Pull Request.
