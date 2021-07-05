<?php

    /***********************************************************************
     * helpers.php
     *
     * CC50
     * Pset 7
     *
     * Helper functions.
     **********************************************************************/


    /*
     * void
     * apologize($message)
     *
     * Apologizes to user by displaying a page with message.
     */

    function apologize($message)
    {
        // require template
        require_once("apology.php");

        // exit immediately since we're apologizing
        exit;
    }


    /*
     * void
     * dump($variable)
     *
     * Facilitates debugging by dumping contents of variable
     * to browser.
     */

    function dump($variable)
    {
        // dump variable with some quick and dirty HTML
        require("dump.php");

        // exit immediately so that we can see what we printed
        exit;
    }


    /*
     * void
     * logout()
     *
     * Logs out current user, if any.  Based on Example #1 at
     * http://us.php.net/manual/en/function.session-destroy.php.
     */

    function logout()
    {
        // unset any session variables
        $_SESSION = array();

        // expire cookie
        if (isset($_COOKIE[session_name()]))
        {
            if (preg_match("{^(/~[^/]+/pset7/)}", $_SERVER["REQUEST_URI"], $matches))
                setcookie(session_name(), "", time() - 42000, $matches[1]);
            else
                setcookie(session_name(), "", time() - 42000);
        }

        // destroy session
        session_destroy();
    }


    /*
     * stock
     * lookup($symbol)
     *
     * Returns a stock by symbol (case-insensitively) else NULL if not found.
     */

    function lookup($symbol)
    {
        // Turn in uppercase
        $symbol = strtoupper($symbol);
        
        // reject symbols that start with ^
        if (preg_match("/^\^/", $symbol))
            return NULL;

        // open connection to Yahoo
        // if (($fp = @fopen(YAHOO . $symbol, "r")) === FALSE) Deprecated
        if (($fp = @fopen(YAHOO_1de4 . $symbol . YAHOO_2de4 . strtotime("-1 week") . YAHOO_3de4 . strtotime("now") . YAHOO_4de4, "r")) === FALSE)
            return NULL;

        // Testing whether the connection to Yahoo was succesfully estabilished
        if (($data = fgetcsv($fp)) === FALSE || count($data) == 1)
            return NULL;
            
        // download second and third lines of CSV file
        $data = fgetcsv($fp);
        $data2 = fgetcsv($fp);
        
        // Ensuring that the date consulted is as recent as possible
        while (strtotime($data[0]) < strtotime($data2[0]))
        {
            $data = $data2;
            $data2 = fgetcsv($fp);
        }

        // close connection to Yahoo
        fclose($fp);

        // instantiate a stock object
        $stock = new Stock();

        // remember stock's symbol and trades
        $stock->symbol = $symbol;
        $stock->timestamp = strtotime($data[0]);
        $stock->time = date_create($data[0]);
        $stock->open = $data[1];
        $stock->high = $data[2];
        $stock->low = $data[3];
        $stock->price = number_format($data[4], 2, ",", ".");
        $stock->adjPrice = $data[5]; //number_format($data[5], 2, ",", ".");
        $stock->volume = $data[6];

        return $stock;
        // return strtotime("now");
    }


    /*
     * void
     * redirect($destination)
     * 
     * Redirects user to destination, which can be
     * a URL or a relative path on the local host.
     *
     * Because this function outputs an HTTP header, it
     * must be called before caller outputs any HTML.
     */

    function redirect($destination)
    {
        // handle URL
        if (preg_match("/^http:\/\//", $destination))
            header("Location: " . $destination);

        // handle absolute path
        else if (preg_match("/^\//", $destination))
        {
            $protocol = (@$_SERVER["HTTPS"]) ? "https" : "http";
            $host = $_SERVER["HTTP_HOST"];
            header("Location: $protocol://$host$destination");
        }

        // handle relative path
        else
        {
            // adapted from http://www.php.net/header
            $protocol = (@$_SERVER["HTTPS"]) ? "https" : "http";
            $host = $_SERVER["HTTP_HOST"];
            $path = rtrim(dirname($_SERVER["PHP_SELF"]), "/\\");
            header("Location: $protocol://$host$path/$destination");
        }

        // exit immediately since we're redirecting anyway
        exit;
    }


    /*
     * void
     * navigator($currentPage)
     * 
     * Build buttons with links to all pages
     */
     
     function navigator($currentPage)
     {
        if ($currentPage != "index.php")
            print('
                <form action="index.php" method="post">
                    <p><input type="submit" value="voltar para página inicial" style="heigth:150px; width:200px;"> 
                </form>');
        
        if (!($currentPage == "quote.php" || $currentPage == "quote2.php"))
            print ('
                <form action="quote.php" method="post">
                    <p><input type="submit" value="Consultar Valor Ação" style="heigth:150px; width:200px;"></p>
                </form>');
        
        if ($currentPage != "sell.php")
            print ('
                <form action="sell.php" method="post">
                    <p><input type="submit" value="vender" style="heigth:150px; width:200px;"> </p>
                </form>');

        if ($currentPage != "buy.php")
            print ('
                <form action="buy.php" method="post">
                    <p><input type="submit" value="comprar" style="heigth:150px; width:200px;"> </p>
                </form>');

        print('<a href="logout.php">log out</a>');
        //  print_r($currentPage);
     }
?>
