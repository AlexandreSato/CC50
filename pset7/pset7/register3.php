<?php

    // require common code
    require_once("includes/common.php"); 

    // get the q parameter from URL and escape for safety
    $q = mysqli_real_escape_string($connection, $_REQUEST["q"]);

    // querying if the username already exists in the database
    if(mysqli_num_rows(mysqli_query($connection, "SELECT uid FROM users WHERE username='$q'")) == 1)
        echo "Este nome de usuário já está em uso, escolha outro!";
    else
        echo "Nome de usuário disponível";

?>
