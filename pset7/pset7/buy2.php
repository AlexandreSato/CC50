<?php

// require common code
require_once("includes/common.php"); 

// validating user input
if (!preg_match("/^\d+$/", $_POST["shares"]))
    apologize("A quantidade de cotas precisa ser um númeiro inteiro não negativo!");
if (!$s = lookup($_POST["symbol"])) // and consulting v.unit from YahooFinance
    apologize ("Você digitou o simbolo corretamente?<br> Ex: GOOG ou NFLX ou ainda TSLA <br><br> Ou pode ser que a conexão do Yahoo esteja falhando");

// escape symbol and shares for safety
$symbols = mysqli_real_escape_string($connection, $_POST["symbol"]);
$buy_shares = mysqli_real_escape_string($connection, $_POST["shares"]);

// verifying if have cash enough
$cash_buy = $s->adjPrice * $buy_shares; // v.unit x qt
$sql = "SELECT cash FROM users WHERE uid={$_SESSION["uid"]}";
if(!($result = mysqli_query($connection, $sql)) || mysqli_num_rows($result)==0)
    apologize("A Consulta de quantidade de dinheiro disponível na carteira falhou");
$row = mysqli_fetch_array($result);
if($cash_buy > $row["cash"])
    apologize("Não pode pagar &#128528;");

// buying
$dateTime = date("Y/m/d H:i:s",strtotime("now"));
$sql = "
    INSERT INTO custody (uids, symbols, shares) VALUES ({$_SESSION["uid"]}, '$s->symbol', '$buy_shares')
    ON DUPLICATE KEY UPDATE shares = shares + '$buy_shares';
    UPDATE users SET cash = cash - '$cash_buy' WHERE uid={$_SESSION["uid"]};
    INSERT INTO history (uids, symbols, shares, price, transacted) VALUES ({$_SESSION["uid"]}, '$s->symbol', '$buy_shares', '$s->adjPrice', '$dateTime')
";
if($connection->multi_query($sql))
    $_SESSION["messages"] = "Comprado!";
else
    apologize("A compra de cotas falhou &#128528;");

// redirect to portfolio
redirect("index.php");
 
?>

<!DOCTYPE html>

<html>

    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="css/styles.css" rel="stylesheet" type="text/css">
        <title>&#129297; CC50 Finanças: Buy2</title>
    </head>
    <bodY>  
        <div id="top">
            <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
        </div>

        <div id="middle">
            <img alt="Em construção" height="150" src="images/construction.gif" width="300">
        </div>

        <div id="bottom">
            <?php
            /* invoking the function to draw the links */ 
            navigator($path = basename($_SERVER["PHP_SELF"]));
            ?>  
        </div>
    </body>
</html>