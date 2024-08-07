CP4 - Interação com o Node-red

GRUPO: 

- Felipe Ferreira rm553680
- Gilson Dias Ramos Junior rm552345
- Gustavo Bezerra Assumção rm553076

DESCRIÇÃO DOS COMPONENTES:

- Arduino UNO
- Protoboard
- Sensores 
	* DHT11 	- para captar a temperatura
	* LDR 		- para captar a luminosidade
	* Ultrassonico 	- para captar a distância
- Jumpers
- Restistor 1k Ohms

INSTRUÇÕES:

O sistema capta o valores (temepratura, luminosidade e distância) a partir dos sensores. Alem disso, ele converte os dados para Json e o manda para o node-red, onde irá interpretar as informações e apresentar em gráficos.