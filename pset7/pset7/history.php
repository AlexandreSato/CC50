<?php

    // require common code
    require_once("includes/common.php"); 

    // Consulting custody table on finance data base
    if (!$history = mysqli_query($connection, "SELECT * FROM history WHERE uids = {$_SESSION["uid"]} ORDER BY transacted"))
      apologize("A consulta a tabela custódia do usuário falhou!");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=0.7">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>&#129297; CC50 Finanças: History</title>
  </head>

  <body>
    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
      <p>Clique no Logo para voltar à página inicial</p>
    </div>


    <div id="middle">
      <?php print("<p>{$_SESSION["messages"]}</p>"); $_SESSION["messages"]=""; ?>
      <br>
      <table style="text-align: left; border: 2px solid #155dc9; tr:nth-child(even){background-color: #5f5d5d;};">
        <tr style="text-align: left; border: 2px solid #155dc9; tr:nth-child(even){background-color: #5f5d5d;};"> 
          <th>Símbolo</th>
          <th>Cotas</th>
          <th>Preço</th>
          <th>Data</th>
        </tr>
        <?php 
          $count = 0;
          while ($row = mysqli_fetch_array($history))
          {
            /* Because nth-child don't worked in this php */
            if ($count % 2 == 0) 
              print("<tr style='text-align: left; border: 2px solid #155dc9; background-color: #777777;'>");
            else
              print("<tr style='text-align: left; border: 2px solid #155dc9;'>");
            
            print("<td>{$row["symbols"]}</td>");
            print("<td>{$row["shares"]}</td>");
            $PRICE = number_format($row["price"], 2, ",", ".");
            print("<td>&#36;{$PRICE}</td>");
            // $dateTime = date_format($row["transacted"],"d/m/Y H:m:s");
            print("<td>{$row["transacted"]}</td>");
            print("</tr>");
            $count++;
          }
        ?>
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
