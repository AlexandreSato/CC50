<?php

    // require common code
    require_once("includes/common.php"); 

    // Consulting custody table on finance data base
    if (!$custody = mysqli_query($connection, "SELECT symbols, shares FROM custody WHERE uids = {$_SESSION["uid"]} ORDER BY symbols"))
      apologize("A consulta a tabela custódia do usuário falhou!");

    // Consulting total cash of the user
    if(!$totalCash = mysqli_query($connection, "SELECT cash FROM users WHERE uid = {$_SESSION["uid"]}"))
      apologize("A consulta do total de dinherio do usuário falhou!");
    $totalCash = mysqli_fetch_array($totalCash);
    $sum = $totalCash["cash"];
    $totalCash = number_format($totalCash["cash"], 2, ",", ".");
    // dump($row["symbols"]);
    // dump($totalCash);
?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>&#129297; CC50 Finanças: Home</title>
  </head>

  <body>
    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>


    <div id="middle">
      <!-- <img alt="Em construção" height="150" src="images/construction.gif" width="300"> -->
      <?php print("<p>{$_SESSION["messages"]}</p>"); $_SESSION["messages"]=""; ?>
      <br>
      <table style="text-align: left; border: 2px solid #155dc9; tr:nth-child(even){background-color: #5f5d5d;};">
        <tr style="text-align: left; border: 2px solid #155dc9; tr:nth-child(even){background-color: #5f5d5d;};"> 
          <th>Symbol</th>
          <th>Cotas</th>
          <th>Preço</th>
          <th>TOTAL</th>
        </tr>
        <?php 
          $count = 0;
          while ($row = mysqli_fetch_array($custody))
          {
            $s = lookup($row["symbols"]);
            if ($count % 2 == 0) /* Because nth-child don't worked in this php */
              print("<tr style='text-align: left; border: 2px solid #155dc9; background-color: #777777;'>");
            else
              print("<tr style='text-align: left; border: 2px solid #155dc9;'>");
            print("<td>{$s->symbol}</td>");
            print("<td>{$row["shares"]}</td>");
            $PRICE = number_format($s->adjPrice, 2, ",", ".");
            print("<td>&#36;{$PRICE}</td>");
            $TOTAL = number_format($row["shares"] * $s->adjPrice, 2, ",", ".");
            print("<td>&#36;{$TOTAL}</td>");
            print("</tr>");
            $sum += $row["shares"] * $s->adjPrice;
            $count++;
          }
        ?>
        <tr>
          <td>CASH</td>
          <td></td>
          <td></td>
          <td> &#36;<?php print $totalCash ?> </td>
        </tr>
        <tr style="font-weight:bold;">
          <td></td>
          <td></td>
          <td></td>
          <td> &#36;<?php print number_format($sum, 2, ",", ".") ?> </td>
        </tr>
      </table>
    </div>

    <div id="bottom">
        <?php
          /* invoking the function to draw the links */ 
          navigator($path = basename($_SERVER["PHP_SELF"]));
        ?>
    </div>

  </body>

</html>
