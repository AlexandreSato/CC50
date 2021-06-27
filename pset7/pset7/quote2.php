<?php

    // require common code
    require_once("includes/common.php"); 

    if (!$stock = lookup($_POST["symbol"]))
        apologize ("Você digitou o simbolo corretamente?<br> Ex: GOOG ou NFLX ou ainda TSLA <br><br> Ou pode ser que a conexão do Yahoo esteja falhando");
?>

<!DOCTYPE html>

<html>

  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: Quote2</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
        <form>
        <table>
          <tr>
            <td>Símbolo da ação consultada:</td>
            <td><input name="symbolConsulted" type="text" value=<?php echo $stock->symbol ?> readonly="readonly"></td>
          </tr>
          <tr>
            <td>Valor da ação consultada:</td>
            <td><input name="value" type="text" value=<?php echo $stock->adjPrice ?> readonly="readonly"></td>
          </tr>
          <tr>
            <td>Data da ação consultada:</td>
            <td><input name="value" type="text" value=<?php echo $stock->time ?> readonly="readonly"></td>
            <tr>
        </table>
      </form>

        <br>
      <form action="quote2.php" method="post">
        <table>
            <td>Símbolo da nova ação a ser consultada:</td>
            <td><input name="symbol" type="text"></td>
          </tr>
            <td></td>
            <td><input type="submit" value="Consultar Yahoo Finance"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      <a href="index.php">voltar</a> para página inicial
    </div>
 
  </body>

</html>