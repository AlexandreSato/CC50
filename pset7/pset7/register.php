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
    <title>&#129297; CC50 Finanças: Register</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="register2.php" method="post">
        <table>
          <tr>
            <td>Usuário:</td>
            <td><input name="username" type="text" autofocus placeholder="Usuário" autocomplete="off" required></td>
          </tr>
          <tr>
            <td>Senha:</td>
            <td><input name="password" type="password" placeholder="Senha" autocomplete="off" required></td>
          </tr>
          <tr>
            <td>Repita senha:</td>
            <td><input name="password2" type="password" placeholder="Repita Senha" autocomplete="off" required></td>
          </tr>
          <tr>
          <tr>
            <td>E-mail para recuperação de senha:</td>
            <td><input name="mail" type="text" placeholder="E-mail p/ recuperação" autocomplete="off" required></td>
          </tr>
          <tr>
            <td></td>
            <td><input type="submit" value="Registrar"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      ou <a href="login.php">logue-se</a> no site
    </div>

  </body>

</html>
