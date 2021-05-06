<?

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: Log in</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="login2.php" method="post">
        <table>
          <tr>
            <td>Usuário:</td>
            <td><input name="username" type="text"></td>
          </tr>
          <tr>
            <td>Senha:</td>
            <td><input name="password" type="password"></td>
          </tr>
          <tr>
            <td></td>
            <td><input type="submit" value="Log In"></td>
          </tr>
        </table>
      </form>
    </div>

    <div id="bottom">
      ou <a href="register.php">registre-se</a> no site
    </div>

  </body>

</html>
