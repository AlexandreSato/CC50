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
    <title>CC50 Finanças: Quote</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="quote2.php" method="post">
        <table>
          <tr>
            <td>Símbolo da ação a ser consultada:</td>
            <td><input name="symbol" type="text"></td>
          </tr>
            <td></td>
            <td><input type="submit" value="Consultar Yahoo Finance"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      ou <a href="index.php">voltar</a> para página inicial
    </div>

    <!-- <div id="bottom">
      Teste de texto
      <?php
        $arr = array("red"=>"login.php", "green"=>"register.php", "blue");
        // $str = '<br>Teste de texto 2';
        // $str .= '<br>Teste de texto 3';
        // echo($arr);
        // print_r($arr);
        foreach($arr as $value => $link)
        {
          echo "<br> <a href=$link> $value </a>";
        }
      ?>
    </div> -->


  </body>

</html>
