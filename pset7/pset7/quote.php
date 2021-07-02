<?php

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>&#129297; CC50 Finanças: Quote</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="quote2.php" method="post" onsubmit="return validateForm(this);">
        <table>
          <tr>
            <td>Ação a ser consultada:</td>
            <td><input name="symbol" type="text" autofocus placeholder="Símbolo ex.: GOOG NFLX TSLA" autocomplete="on" required ></td>
          </tr>
            <td></td>
            <td><input type="submit" value="Consultar Yahoo Finance"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      <form action="index.php" method="post">
          <p><input type="submit" value="voltar para página inicial" style="heigth:150px; width:200px;"> 
      </form>
      <form action="sell.php" method="post">
          <p><input type="submit" value="vender" style="heigth:150px; width:200px;"> 
      </form>
      <a href="logout.php">log out</a>
    </div>

  </body>

</html>
