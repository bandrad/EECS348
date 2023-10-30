function verify(){
 
  var password = document.getElementById(“password”).value;
  var vPassword = document.getElementById(“confirm”).value;
  
  if(password.length < 8) 
  {
		alert(“Error: Password must be at least 8 characters”); 
  }
  
  if(password.value != vPassword.value)
  {
    alert("Error: Passwords do not match!");
  }
  else
  {
    alert("Passwords Match!");
  }
  
  
}
