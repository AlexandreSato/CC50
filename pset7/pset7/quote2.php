<?php

    // require common code
    require_once("includes/common.php"); 

    // getting Share value on Yahoo Finance
    if (!$stock = lookup($_POST["symbol"]))
        apologize ("Você digitou o simbolo corretamente?<br> Ex: GOOG ou NFLX ou ainda TSLA <br><br> Ou pode ser que a conexão do Yahoo esteja falhando");
?>

<!DOCTYPE html>

<html>

  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>&#129297; CC50 Finanças: Quote2</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <div style="text-align: center">
        <br><br>A ação <?php print $stock->symbol; ?> atualmente custa US$ <?php print number_format($stock->adjPrice, 2, ",", "."); ?> <br> <?php print date_format($stock->time, "d/m/Y"); ?>
      </div>

      <br>
      <p>Deseja uma NOVA Consulta? Símbolo&colon;</p>
      <form action="quote2.php" method="post">
        <table>
          <tr>
            <td><input name="symbol" type="text" autofocus placeholder="Símbolo ex.: GOOG NFLX TSLA" autocomplete="on" required></td>
          </tr>
          <tr>
            <td><input type="submit" value="Consultar Yahoo Finance"></td>
          </tr>
        </table>
      </form>
    </div>

    <br>
    <div id="bottom">
      <?php
        /* invoking the function to draw the links */ 
        navigator($path = basename($_SERVER["PHP_SELF"]));
       ?>
    </div>
 
  </body>

</html>