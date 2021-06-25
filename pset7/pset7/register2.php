<?php

    // require common code
    require_once("includes/common.php"); 

    // validating imputings from password
    if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["password2"]))
        apologize("Não preenchemos algum campo?");
    if ($_POST["password"] != $_POST["password2"])
        apologize("As senhas digitadas não coincidem");
          
    // escape username and password for safety
    $username = mysqli_real_escape_string($connection, $_POST["username"]);
    $password = mysqli_real_escape_string($connection, $_POST["password"]);
    
    // querying if the usrname already exists in the database
    if(mysqli_num_rows(mysqli_query($connection, "SELECT uid FROM users WHERE username='$username'")) == 1)
        apologize("O nome de usuário deseja já está em utilização, escolha outro!");
    
    // prepare SQL
    $sql = "INSERT INTO users (username, password, cash) VALUES('$username', '$password', 10000)";

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
