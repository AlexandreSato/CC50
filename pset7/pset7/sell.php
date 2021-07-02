<?php

    // require common code
    require_once("includes/common.php");

    // Consulting custody table on finance data base
    if (!$custody = mysqli_query($connection, "SELECT symbols, shares FROM custody WHERE uids = {$_SESSION["uid"]} ORDER BY symbols"))
    apologize("A consulta à tabela custódia do usuário falhou!");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>&#129297; CC50 Finanças: Sell</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="sell2.php" method="post">
        <select name="symbol" required>
          <option disabled selected value="">Símbolo da Ação</option>
          <?php 
            while($row = mysqli_fetch_array($custody))
            {
              print("<option value={$row["symbols"]}>{$row["symbols"]}</option>");
            }
          ?>
        </select>
        <table>
          <tr>
            <td><input name="shares" type="text" autofocus placeholder="Quantidade de cotas" autocomplete="on" required ></td>
          </tr><tr></tr>
          <tr>
            <td><input type="submit" value="Venda!!"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      <form action="index.php" method="post">
          <p><input type="submit" value="voltar para página inicial" style="heigth:150px; width:200px;"> 
      </form>
      <form action="quote.php" method="post">
          <p><input type="submit" value="Consultar Valor Ação" style="heigth:150px; width:200px;"> 
      </form>
      <a href="logout.php">log out</a>
    </div>


  </body>

</html>
