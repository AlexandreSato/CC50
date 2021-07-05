
<?php

// require common code
require_once("includes/common.php"); 

// validating user input
if (!preg_match("/^\d+$/", $_POST["shares"]))
    apologize("A quantidade de cotas precisa ser um númeiro inteiro não negativo!");

// escape symbol and shares for safety
$symbols = mysqli_real_escape_string($connection, $_POST["symbol"]);
$sale_shares = mysqli_real_escape_string($connection, $_POST["shares"]);

// prepare SQL
$sql = "SELECT * FROM custody WHERE uids={$_SESSION["uid"]} AND symbols='$symbols'";

// execute query
if(!($result = mysqli_query($connection, $sql)) || mysqli_num_rows($result)==0)
    apologize("A Consulta de quantidade de cotas da ação solicitada falhou");

// verifying if have shares enough
$row = mysqli_fetch_array($result);
if($sale_shares > $row["shares"])
    apologize("Você possui apenas {$row["shares"]} cota(s) de '$symbols' &#128528;");

// selling
$s = lookup($row["symbols"]); // consulting v.unit from YahooFinance
$cash_sell = $s->adjPrice * $sale_shares; // v.unit x qt
if($sale_shares == $row["shares"])
    $sql = "DELETE FROM custody WHERE uids={$_SESSION["uid"]} AND symbols='$symbols';";
else
    $sql = "UPDATE custody SET shares = shares - '$sale_shares' WHERE uids={$_SESSION["uid"]} AND symbols='$symbols';";
$sql .= "UPDATE users SET cash = cash + '$cash_sell' WHERE uid={$_SESSION["uid"]} ";
if($connection->multi_query($sql))
    $_SESSION["messages"] = "Vendido!";
else
    apologize("A venda de cotas falhou &#128528;");

// redirect to portfolio
redirect("index.php");

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