<?php

    // require common code
    require_once("includes/common.php"); 

    // validating imputings from password
    if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["password2"]) || empty($_POST["mail"]))
        apologize("Não preenchemos algum campo?");
    if ($_POST["password"] != $_POST["password2"])
        apologize("As senhas digitadas não coincidem");
          
    // escape username and password for safety
    $username = mysqli_real_escape_string($connection, $_POST["username"]);
    $password = mysqli_real_escape_string($connection, $_POST["password"]);
    $mail = mysqli_real_escape_string($connection, $_POST["mail"]);

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
    
    // querying if the username already exists in the database
    if(mysqli_num_rows(mysqli_query($connection, "SELECT uid FROM users WHERE username='$username'")) == 1)
        apologize("O nome de usuário deseja já está em utilização, escolha outro!");
    
    // prepare SQL
    $sql = "INSERT INTO users (username, password, cash, mail) VALUES('$username', '$password', 10000, '$mail')";

    // execute query
    if(mysqli_query($connection, $sql))
    {
        // cache uid in session
        $_SESSION["uid"] = mysqli_insert_id($connection);
        
        // redirect to portfolio
        redirect("index.php");
    }

    // else report error
    else
        echo "Error: " . $sql . "<br>" . mysqli_error($connection);

?>
