<html>
<head>
<meta charset="UTF-8" />
  <link rel="stylesheet" type="text/css" href="css/style.css">
</head>


<?php
if (isset($_POST['W00-On']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/scanGPIO-01");
}
if (isset($_POST['W00-Off']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/stopScanGPIO");
}

if (isset($_POST['W01-On']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/FlashPin01GPIO");
}
if (isset($_POST['W01-Off']))
{
exec("sudo pkill FlashPin01GPIO");
}

if (isset($_POST['W03-On']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/FlashPin03GPIO");
}
if (isset($_POST['W03-Off']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/stopScanGPIO");
}

if (isset($_POST['W04-On']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/FlashPin04GPIO");
}
if (isset($_POST['W04-Off']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/stopScanGPIO");
}

if (isset($_POST['W05-On']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/FlashPin05GPIO");
}
if (isset($_POST['W05-Off']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/stopScanGPIO");
}
?>

<form method="post">
<H1>

&nbsp;
<button style="height:15%;width:45%;color:white;background:green;" class="btn" name="W00-On"><h1>scanGPIO</h1></button>&nbsp; 
<button style="height:15%;width:45%;color:white;background:orange;" class="btn" name="W00-Off"><h1>Stop scanGPIO</h1></button>&nbsp;<br><br>

&nbsp;
<button style="height:15%;width:45%;color:white;background:green;" class="btn" name="W01-On"><h1>FlashPin01GPIO</h1></button>&nbsp; 
<button style="height:15%;width:45%;color:white;background:orange;" class="btn" name="W01-Off"><h1>Stop FlashPin01GPIO</h1></button>&nbsp;<br><br>

&nbsp;
<button style="height:15%;width:45%;color:white;background:green;" class="btn" name="W03-On"><h1>FlashPin03GPIO</h1></button>&nbsp; 
<button style="height:15%;width:45%;color:white;background:orange;" class="btn" name="W03-Off"><h1>Stop FlashPin03GPIO</h1></button>&nbsp;<br><br>

&nbsp;
<button style="height:15%;width:45%;color:white;background:green;" class="btn" name="W04-On"><h1>FlashPin04GPIO</h1></button>&nbsp; 
<button style="height:15%;width:45%;color:white;background:orange;" class="btn" name="W04-Off"><h1>Stop FlashPin04GPIO</h1></button>&nbsp;<br><br>

&nbsp;
<button style="height:15%;width:45%;color:white;background:green;" class="btn" name="W05-On"><h1>FlashPin05GPIO</h1></button>&nbsp; 
<button style="height:15%;width:45%;color:white;background:orange;" class="btn" name="W05-Off"><h1>Stop FlashPin05GPIO</h1></button>&nbsp;<br><br>

</H1>
</form> 


</html>
