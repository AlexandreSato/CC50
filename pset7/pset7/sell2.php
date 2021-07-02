
<?php

// require common code
require_once("includes/common.php"); 

/*
// escape username and password for safety
$username = mysqli_real_escape_string($connection, $_POST["username"]);
$password = mysqli_real_escape_string($connection, $_POST["password"]);

// prepare SQL
$sql = "SELECT uid FROM users WHERE username='$username' AND password='$password'";

// execute query
$result = mysqli_query($connection, $sql);

// if we found a row, remember user and redirect to portfolio
if (mysqli_num_rows($result) == 1)
{
    // grab row
    $row = mysqli_fetch_array($result);
    
    // cache uid in session
    $_SESSION["uid"] = $row["uid"];
    
    // redirect to portfolio
    redirect("index.php");
}

// else report error
else
apologize("Usuário e/ou senha inválidos!");
*/
?>




<!DOCTYPE html>

<html>

    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="css/styles.css" rel="stylesheet" type="text/css">
        <title>&#129297; CC50 Finanças: Sell2</title>
    </head>
    <bodY>  
        <div id="top">
            <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
        </div>

        <div id="middle">
            <img alt="Em construção" height="150" src="images/construction.gif" width="300">
        </div>
    </body>
</html>