<?php

    // require common code
    require_once("includes/common.php"); 

    echo "Hello Quote2 <br>";

    if (!$test2 = lookup("NFLX"))
        echo "Não funcionou lookup<br>";
    
     dump($test2);

?>