function format()

{
 
var pr = document.getElementById(“textR”).value;
var pg = document.getElementById(“textG”).value;
var pb = document.getElementById(“textB”).value;

document.getElementById(“text”).style.color = "rgb("pr","pg","pb")";


var width = document.getElementById(“width”).value;
document.getElementById(“text”).style.borderWidth = "width";
  

var br = document.getElementById(“borderR”).value;
var bg = document.getElementById(“borderG”).value;
var bb = document.getElementById(“borderB”).value;
  
document.getElementById(“text”).style.borderColor = "rgb("borderR","borderG","borderB")";
  
}