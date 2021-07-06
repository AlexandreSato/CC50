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
    <meta name="viewport" content="width=device-width, initial-scale=0.8">
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
        <select name="symbol" required autofocus>
          <option disabled selected value="" autocomplete="off">Símbolo da Ação</option>
          <?php 
            while($row = mysqli_fetch_array($custody))
            {
              print("<option value={$row["symbols"]}>{$row["symbols"]}</option>");
            }
          ?>
        </select>
        <table>
          <tr><td></td></tr><tr><td></td></tr><tr><td></td></tr>
          <tr><td></td></tr>
          <tr>
            <td><input name="shares" type="text" placeholder="Quantidade de cotas" autocomplete="off" required ></td>
          </tr>
          <tr>
            <td><input type="submit" value="Venda!!"></td>
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
