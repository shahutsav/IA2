# IA2

<h3>Introduction</h3>
<p>This circuit uses a force sensitive resistor to detect the amount of pressure applied. This value is then used to light up the Neopixel LED's based on the percentage of pressure. This data is then published to the photon cloud for visualizing the data on the website which the photon subscribes to for producing results on the output. An additional piezo buzzer checks for the high pressure conditions and plays the Game of Thrones melody. </p>

<h3> Reading data </h3>
<p> The input value of a force sensitive resistor ranges from 0 to 4096. In order to have a working domain, I scaled down the values from 4096 to 1024. This was done with a single command <b>int fsrReading = analogRead(fsrPin)/4;</b>

<h3> Visualization </h3>
<p>I worked with <a href="https://github.com/ugomeda/d3-liquid-fill-gauge">Liquid Fill Gauge</a> which is based on <a href="d3js.org">d3</a> This is a different visualization method as compared to IA1. </p>

<h3>Circuit Diagram </h3>
The completed circuit diagram is shown below. It includes the following connections -
<ul>
<li>FSR connected to A0 </li>
<li>Piezo Buzzer connected to D2 </li>
<li>Neopixel 16 ring LED connected to D1 </li>
</ul>
<img src = "circuit.jpg">

<hr>
