<html>
<head>
<meta charset="UTF-8" />
  <link rel="stylesheet" type="text/css" href="css/style.css">
</head>


<?php
if (isset($_POST['Winch01Up']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch01Up");
}
if (isset($_POST['Winch01Stop']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch01Stop");
}
if (isset($_POST['Winch01Down']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch01Down");
}
if (isset($_POST['Winch02Up']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch02Up");
}
if (isset($_POST['Winch02Stop']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch02Stop");
}
if (isset($_POST['Winch02Down']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch02Down");
}
if (isset($_POST['Winch03Up']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch03Up");
}
if (isset($_POST['Winch03Stop']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch03Stop");
}
if (isset($_POST['Winch03Down']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch03Down");
}
if (isset($_POST['Winch04Up']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch04Up");
}
if (isset($_POST['Winch04Stop']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch04Stop");
}
if (isset($_POST['Winch04Down']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/Winch04Down");
}
if (isset($_POST['MusicOn']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/MusicOn");
}
if (isset($_POST['MusicOff']))
{
exec("sudo /home/pi/TinyHome/RaspberryPiPrograms/MusicOff");
}
?>

<form method="post">
<button style="height:12%;width:30%;color:white;background:blue;" class="btn" name="Winch01Up">Winch 1 Up</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:red;" class="btn" name="Winch01Stop">Winch 1 Stop</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:green;" class="btn" name="Winch01Down">Winch 1 Down</button>&nbsp;<br><br>

<button style="height:12%;width:30%;color:white;background:blue;" class="btn" name="Winch02Up">Winch 2 Up</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:red;" class="btn" name="Winch02Stop">Winch 2 Stop</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:green;" class="btn" name="Winch02Down">Winch 2 Down</button>&nbsp;<br><br>

<button style="height:12%;width:30%;color:white;background:blue;" class="btn" name="Winch03Up">Winch 3 Up</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:red;" class="btn" name="Winch03Stop">Winch 3 Stop</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:green;" class="btn" name="Winch03Down">Winch 3 Down</button>&nbsp;<br><br>

<button style="height:12%;width:30%;color:white;background:blue;" class="btn" name="Winch04Up">Winch 4 Up</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:red;" class="btn" name="Winch04Stop">Winch 4 Stop</button>&nbsp;
<button style="height:12%;width:30%;color:white;background:green;" class="btn" name="Winch04Down">Winch 4 Down</button>&nbsp;<br><br>

<button style="height:12%;width:40%;color:white;background:blue;" class="btn" name="MusicOn">Music On</button>&nbsp;
<button style="height:12%;width:40%;color:white;background:green;" class="btn" name="MusicOff">Music Off</button>&nbsp;<br><br>

<button style="height:12%;width:40%;color:white;background:blue;" class="btn" name="MoodLightingOn">Mood Lighting On</button>&nbsp;
<button style="height:12%;width:40%;color:white;background:green;" class="btn" name="MoodLightingOff">Mood Lighting Off</button>&nbsp;<br><br>

</form> 


</html>
