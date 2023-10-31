function format()

{
 
var text = document.getElementById("text");

var bcR = document.getElementById("bcR").value;
var bcG = document.getElementById("bcG").value;
var bcB = document.getElementById("bcB").value;

text.style.borderColor = 'rgb(${bcR},${bcG}, ${bcB})';

var width = document.getElementById("width").value;
text.style.borderWidth = width;
  

var br = document.getElementById("bgR").value;
var bg = document.getElementById("bgG").value;
var bb = document.getElementById("bgB").value;
  
text.style.backgroundColor = 'rgb(${br},${bg}, ${bb})';
  
}
