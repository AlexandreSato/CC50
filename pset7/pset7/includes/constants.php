<?php

    /***********************************************************************
     * constants.php
     *
     * CC50
     * Pset 7
     *
     * Constantes globais
     **********************************************************************/


    // o nome do seu banco de dados
    define("DB_NAME", "finance");

    // o administrador do seu banco de dados
    define("DB_USER", "sato");

    // a senha do seu banco de dados
    define("DB_PASS", "x$#Ab79CcD156.4");

    // o servidor onde o seu banco de dados está hospedado
    define("DB_SERVER", "localhost");

    // URL do Yahoo Finanças
    // define("YAHOO", "http://download.finance.yahoo.com/d/quotes.csv?f=snl1d1t1c1ohg&s="); // Deprecated
    define("YAHOO_1de4", "https://query1.finance.yahoo.com/v7/finance/download/");
    define("YAHOO_2de4", "?period1=");
    define("YAHOO_3de4", "&period2=");
    define("YAHOO_4de4", "&interval=1d&events=history&includeAdjustedClose=true");
    
    // estudando o GET enviado pelo Yahoo Finance
// https://query1.finance.yahoo.com/v7/finance/download/TSLA?period1=1593025649&period2=1624561649&interval=1d&events=history&includeAdjustedClose=true
// https://query1.finance.yahoo.com/v7/finance/download/NFLX?period1=1593033776&period2=1624569776&interval=1d&events=history&includeAdjustedClose=true
// https://query1.finance.yahoo.com/v7/finance/download/NFLX?period1=1593033776&period2=1624569776&interval=1d&events=history&includeAdjustedClose=true
// https://query1.finance.yahoo.com/v7/finance/download/NFLX?period1=1623974400&period2=1624233600&interval=1d&events=history&includeAdjustedClose=true

    // o gmail do emissor
    define("GMAIL_SENDER", "alexandrenoburaru@gmail.com");
    
    // a senha gmail
    define ("GMAIL_PASS", "dErt%$58FT");

?>
