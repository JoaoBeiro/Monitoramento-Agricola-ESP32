# Monitoramento Agrícola ESP32

## Objetivo do Projeto

Este projeto tem como objetivo criar um sistema inteligente de monitoramento agrícola utilizando o microcontrolador ESP32 e quatro sensores. O sistema coleta dados ambientais e toma decisões automatizadas para otimizar o uso de recursos, como a irrigação e o controle climático.

## Sensores Utilizados

1. **DHT22 (Umidade e Temperatura)**:
   - Mede a umidade e a temperatura do ambiente, ajustando a irrigação com base nesses valores.
   
2. **HC-SR04 (Ultrassom)**:
   - Mede a distância de líquidos em reservatórios de água, monitorando o nível de água disponível para irrigação.
   
3. **PIR (Sensor de Movimento)**:
   - Detecta a presença de animais ou pessoas em áreas monitoradas, sendo útil para a segurança da fazenda.
   
4. **LDR (Sensor de Luz)**:
   - Monitora a intensidade da luz solar, permitindo ajustar a irrigação conforme a quantidade de luz recebida.

## Desenho do Circuito Completo

O circuito foi montado no simulador Wokwi. Abaixo, segue o link para a simulação:

[Link para simulação no Wokwi](COLE O LINK AQUI)

## Como Configurar e Rodar o Projeto

1. **Simulação no Wokwi**:
   - Acesse o link da simulação no Wokwi.
   - Pressione "Play" para iniciar a simulação do sistema de monitoramento.

2. **Rodar o projeto localmente com ESP32**:
   - Clone este repositório:
     ```bash
     git clone https://github.com/JoaoBeiro/Monitoramento-Agricola-ESP32.git
     ```
   - Carregue o código na sua placa ESP32 usando a Arduino IDE ou VSCode com PlatformIO.
   - Instale as bibliotecas necessárias:
     - `DHT.h`
     - `Ultrasonic.h`

3. **Bibliotecas Necessárias**:
   - Para rodar o projeto, você precisará das seguintes bibliotecas:
     - **DHT**: Para medir temperatura e umidade.
     - **Ultrasonic**: Para medir distância com o sensor HC-SR04.

## Testes Realizados

Durante o desenvolvimento, foram realizados os seguintes testes:

1. **Testes de temperatura e umidade**:
   - O sensor DHT22 mediu a temperatura e umidade com precisão, ajustando a irrigação de acordo com os parâmetros definidos.

2. **Testes de nível de água**:
   - O sensor HC-SR04 mediu o nível de água e acionou a irrigação automaticamente quando o nível estava baixo.

3. **Testes de movimento**:
   - O sensor PIR detectou a presença de movimento de maneira confiável.

4. **Testes de luminosidade**:
   - O sensor LDR ajustou a irrigação conforme a quantidade de luz solar.

## Prints do Sistema em Funcionamento

Os resultados dos testes podem ser vistos nos prints armazenados na pasta `/tests`.

## Contribuições

Para contribuir, crie uma branch própria e envie uma Pull Request.
