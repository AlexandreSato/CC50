<?php

// require common code
require_once("includes/common.php"); 

// Include required phpmailer files
require 'includes/PHPMailer/PHPMailer.php';
require 'includes/PHPMailer/SMTP.php';
require 'includes/PHPMailer/Exception.php';

// Define name spaces
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;


// validating user input
if (empty($_POST["username"]) && empty($_POST["mail"]))
    apologize("Não preenchemos algum campo?");

// escape symbol and shares for safety
$username = mysqli_real_escape_string($connection, $_POST["username"]);
$mail = mysqli_real_escape_string($connection, $_POST["mail"]);


// verifying password
if(empty($_POST["mail"]))
$sql = "SELECT * FROM users WHERE username='$username'";
else
{
    // turn the user input data in lowercase
    $mail = strtolower($mail);
    // strip unnecessary characters (extra space, tab, new line) from the user input data 
    $mail = trim($mail);
    // remove backslashes (\) from the user input data 
    $mail = stripslashes($mail);
    // in the name of safety converting (<script>) in (&lt;script&gt;)
    $mail = htmlspecialchars($mail);
    // check if e-mail address is well-formated
    if(!filter_var($mail, FILTER_VALIDATE_EMAIL))
    apologize("O e-mail informado não existe");
    $sql = "SELECT * FROM users WHERE username='$username' OR mail='$mail'";
}
if(!($result = mysqli_query($connection, $sql)))
    apologize("A Consulta da senha do usuário no banco de dados falhou");
if(mysqli_num_rows($result)==0)
    apologize("Usuário ou e-mail não registrado!");
$row = mysqli_fetch_array($result);
$forgted_pass = $row["password"];
$forgted_user = $row["username"];
$forgted_mail = $row["mail"];

// sending e-mail
    // create instance of phpmailer
    $mail = new PHPMailer();

    // set mailer to use smtp
    $mail->isSMTP();

    // define smtp host
    $mail->Host = "smtp.gmail.com";

    // enable smtp authentication
    $mail->SMTPAuth = "true";

    // set type of encryption (ssl/tls)
    $mail->SMTPSecure = "tls";

    // set port to connect smtp
    $mail->Port = "587";

    // set gmail username
    $mail->Username = "alexandrenoburaru@gmail.com";

    // set gmail password
    $mail->Password = GMAIL_PASS;

    // set email subject
    $mail->Subject = "Recuperacao de sua senha do site CC50 Financas";

    // set sender email
    $mail->setFrom("alexandrenoburaru@gmail.com");

    // enable HTML
    $mail->isHTML(true);

    // email body
    $mail->Body = "<h1>O seu nome de usuario e :" .$forgted_user. "</h1><br><h2>E a sua senha e: " .$forgted_pass. "</h2>";

    // add recipient
    $mail->addAddress($forgted_mail);

    // finally send email
    if($mail->Send())
    {
        $_SESSION["messages"]="E-mail de recuperação enviado com sucesso";
        redirect("index.php"); // redirect to portfolio
    }
    else
        apologize("O envio do e-mail com a sua senha falhou");

    // closing smtp connection
    $mail->smtpClose();
 
?>


<!DOCTYPE html>

<html>

    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="css/styles.css" rel="stylesheet" type="text/css">
        <title>&#129297; CC50 Finanças: Forget2</title>
    </head>
    <bodY>  
        <div id="top">
            <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
        </div>

        <div id="middle">
            <img alt="Em construção" height="150" src="images/construction.gif" width="300">
        </div>

        <div id="bottom">
            <?php
            /* invoking the function to draw the links */ 
            navigator($path = basename($_SERVER["PHP_SELF"]));
            ?>  
        </div>
    </body>
</html>
