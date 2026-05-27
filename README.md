<div align="center">

# AirGuard STM32

## Sistema de Monitoramento de Qualidade do Ar com STM32 Blue Pill e MQ-135

</div>

---

## Integrantes

<table>
  <tr>
    <th>Nome</th>
    <th>Contribuição</th>
  </tr>
  <tr>
    <td>Victor Gomes da Costa</td>
    <td>Desenvolvimento do firmware embarcado, integração do sensor MQ-135, leitura ADC, lógica de classificação da qualidade do ar e documentação.</td>
  </tr>
  <tr>
    <td>Gisleno Junior</td>
    <td>Montagem do circuito eletrônico, testes de hardware, validação do sistema e auxílio na integração dos componentes.</td>
  </tr>
</table>

---

## Descrição do Projeto

O projeto <strong>AirGuard STM32</strong> consiste em um sistema embarcado desenvolvido utilizando a placa <strong>STM32 Blue Pill</strong> e o sensor de gases <strong>MQ-135</strong> para monitoramento da qualidade do ar em ambientes internos.

O sistema realiza a leitura analógica do sensor, processa os dados obtidos e classifica a qualidade do ar em diferentes níveis, acionando LEDs e buzzer conforme a condição detectada.

---

## Objetivo

Desenvolver um sistema embarcado capaz de detectar alterações na qualidade do ar em tempo real, utilizando recursos estudados na disciplina de Microcontroladores.

---

## Tecnologias Utilizadas

<ul>
  <li>Linguagem C</li>
  <li>STM32CubeIDE</li>
  <li>STM32 HAL Library</li>
  <li>STM32 Blue Pill - STM32F103C8T6</li>
  <li>Sensor MQ-135</li>
</ul>

---

## Componentes Utilizados

<table>
  <tr>
    <th>Componente</th>
    <th>Quantidade</th>
  </tr>
  <tr>
    <td>STM32 Blue Pill</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Sensor MQ-135</td>
    <td>1</td>
  </tr>
  <tr>
    <td>LED Verde</td>
    <td>1</td>
  </tr>
  <tr>
    <td>LED Amarelo</td>
    <td>1</td>
  </tr>
  <tr>
    <td>LED Vermelho</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Buzzer</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Botão Push Button</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Resistores</td>
    <td>Diversos</td>
  </tr>
  <tr>
    <td>Protoboard</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Jumpers</td>
    <td>Diversos</td>
  </tr>
</table>

---

## Funcionalidades Implementadas

<ul>
  <li>Leitura analógica do sensor MQ-135</li>
  <li>Uso do ADC de 12 bits da STM32</li>
  <li>Classificação da qualidade do ar</li>
  <li>Indicação visual por LEDs</li>
  <li>Alarme sonoro com buzzer</li>
  <li>Botão físico para calibração</li>
  <li>Organização modular do código-fonte</li>
</ul>

---

## Classificação da Qualidade do Ar

<table>
  <tr>
    <th>Status</th>
    <th>Condição</th>
    <th>Ação</th>
  </tr>
  <tr>
    <td>Ar Bom</td>
    <td>Valor ADC baixo</td>
    <td>LED verde ligado</td>
  </tr>
  <tr>
    <td>Ar Moderado</td>
    <td>Valor ADC intermediário</td>
    <td>LED amarelo ligado</td>
  </tr>
  <tr>
    <td>Ar Ruim</td>
    <td>Valor ADC alto</td>
    <td>LED vermelho ligado e buzzer acionado</td>
  </tr>
</table>

---

## Estrutura do Projeto

```txt
Core/
├── Inc/
│   ├── main.h
│   └── air_quality.h
│
└── Src/
    ├── main.c
    └── air_quality.c

    Ligações do Circuito
<table> <tr> <th>MQ-135</th> <th>STM32 Blue Pill</th> </tr> <tr> <td>VCC</td> <td>5V</td> </tr> <tr> <td>GND</td> <td>GND</td> </tr> <tr> <td>AO</td> <td>PA0</td> </tr> </table> <br> <table> <tr> <th>Componente</th> <th>Pino STM32</th> </tr> <tr> <td>LED Verde</td> <td>PA1</td> </tr> <tr> <td>LED Amarelo</td> <td>PA2</td> </tr> <tr> <td>LED Vermelho</td> <td>PA3</td> </tr> <tr> <td>Buzzer</td> <td>PA4</td> </tr> <tr> <td>Botão de calibração</td> <td>PB0</td> </tr> </table>
Proteção do ADC

A placa STM32 Blue Pill trabalha com nível lógico de <strong>3.3V</strong>. Como a saída analógica do MQ-135 pode chegar próximo de <strong>5V</strong>, é necessário utilizar um divisor de tensão para proteger o pino ADC da STM32.

Exemplo de divisor de tensão:

MQ-135 AO ---- Resistor 10k ---- PA0 ---- Resistor 20k ---- GND
Esquemático Simplificado
+------------------+             +----------------------+
|     MQ-135       |             |   STM32 Blue Pill    |
|                  |             |                      |
| VCC -------------+------------> 5V                   |
| GND -------------+------------> GND                  |
| AO --------------+------------> PA0 / ADC1_IN0       |
+------------------+             |                      |
                                 | PA1 -> LED Verde     |
                                 | PA2 -> LED Amarelo   |
                                 | PA3 -> LED Vermelho  |
                                 | PA4 -> Buzzer        |
                                 | PB0 -> Botão Calib.  |
                                 +----------------------+
Principais Bugs Encontrados
<table> <tr> <th>Bug</th> <th>Descrição</th> <th>Solução</th> </tr> <tr> <td>Oscilação no ADC</td> <td>Os valores lidos pelo sensor variavam muito rapidamente.</td> <td>Aplicação de leituras periódicas com delay e possibilidade de média simples.</td> </tr> <tr> <td>Aquecimento do sensor</td> <td>O MQ-135 precisa de tempo para estabilizar as leituras.</td> <td>Aguardar alguns minutos antes de considerar as leituras confiáveis.</td> </tr> <tr> <td>Risco no pino ADC</td> <td>A saída do sensor pode chegar próximo de 5V.</td> <td>Uso de divisor de tensão antes do pino PA0.</td> </tr> <tr> <td>Falso acionamento do buzzer</td> <td>Pequenas oscilações podiam ativar o alarme.</td> <td>Definição de limites para classificar os níveis de qualidade do ar.</td> </tr> </table>
Lista de Tarefas Futuras
<ul> <li>Implementar média móvel para suavizar as leituras do ADC</li> <li>Adicionar display OLED I2C</li> <li>Exibir valor ADC e status da qualidade do ar no display</li> <li>Adicionar comunicação UART para depuração</li> <li>Salvar calibração em memória Flash</li> <li>Implementar registro histórico das leituras</li> <li>Adicionar módulo Wi-Fi para integração IoT</li> <li>Melhorar o esquemático em ferramenta como Fritzing, KiCad ou EasyEDA</li> </ul>
Link do Repositório
https://github.com/SEU-USUARIO/airguard-stm32
Datasheet do Sensor MQ-135
https://www.handsontec.com/dataspecs/MQ-135%20Gas%20Sensor.pdf
Como Executar o Projeto
<ol> <li>Abrir o projeto no STM32CubeIDE.</li> <li>Configurar a placa como STM32F103C8T6.</li> <li>Configurar o ADC no pino PA0.</li> <li>Configurar os GPIOs dos LEDs, buzzer e botão.</li> <li>Compilar o projeto.</li> <li>Gravar o código na STM32 Blue Pill usando ST-Link.</li> <li>Montar o circuito conforme as conexões descritas.</li> <li>Aguardar o aquecimento inicial do sensor MQ-135.</li> <li>Testar a leitura aproximando álcool, fumaça ou variações de gases do sensor.</li> </ol>
Conceitos da Disciplina Utilizados
<ul> <li>GPIO</li> <li>ADC</li> <li>Temporização</li> <li>Leitura de sensores analógicos</li> <li>Controle de periféricos</li> <li>Sistemas embarcados</li> <li>Programação em linguagem C</li> <li>Organização modular de firmware</li> </ul>
Licença

Projeto acadêmico desenvolvido para a disciplina de Microcontroladores.