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
        // reject symbols that start with ^
        if (preg_match("/^\^/", $symbol))
            return NULL;

        // open connection to Yahoo
        // if (($fp = @fopen(YAHOO . $symbol, "r")) === FALSE)
        if (($fp = @fopen("https://query1.finance.yahoo.com/v7/finance/download/NFLX?period1=1623974400&period2=1624233600&interval=1d&events=history&includeAdjustedClose=true", "r")) === FALSE)
            return NULL;

        // Testing whether the connection to Yahoo was succesfully estabilished
        if (($data = fgetcsv($fp)) === FALSE || count($data) == 1)
            return NULL;
            
        // download first line of CSV file
        $data = fgetcsv($fp);

        // close connection to Yahoo
        fclose($fp);

        // instantiate a stock object
        $stock = new Stock();

        // remember stock's symbol and trades
        //$stock->time = $data[0]; //strtotime($data[0]      /* $data[3] . " " . $data[4] */);
        $stock->open = $data[1];
        $stock->high = $data[2];
        $stock->low = $data[3];
        $stock->price = $data[4];
        $stock->adjPrice = $data[5];
        $stock->volume = $data[6]

        return $stock;

        // return $data; 
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

?>
