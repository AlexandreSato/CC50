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
    <title>&#129297; CC50 Finanças: Forget</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <p>Preencha um dos campos abaixo</p>
      <form action="forget2.php" method="post">
        <table>
          <tr>
            <td>Usuário:</td>
            <td><input name="username" type="text" autofocus placeholder="Usuário" autocomplete="off" ></td>
          </tr>
          <tr>
            <td>E-mail para recuperação de senha:</td>
            <td><input name="mail" type="text" placeholder="E-mail p/ recuperação" autocomplete="off" ></td>
          </tr>
          <tr>
            <td></td>
            <td><input type="submit" value="Envie-me !"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      ou <a href="register.php">registre-se</a> no site
    </div>

  </body>

</html>
